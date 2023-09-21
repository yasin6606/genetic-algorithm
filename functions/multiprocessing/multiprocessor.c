#include "../../includes/sharedLib.h"
#include "../../includes/types/functionTypedef.h"
#include "../../includes/sharedMemory.h"
#include "../../includes/sharedMacros.h"

void *
multiprocessor(size_t tasks, size_t chromosomeLen, size_t sharedMemLen, size_t memSizeType, sub_process_t subProcess, size_t argsNum, ...) {
    void *sharedMem = arraySharedMemory(sharedMemLen, memSizeType);
    int cores = get_nprocs(), childShare = floor(tasks / cores), remained = tasks % cores,
            *defineStartIdx = (int *) calloc(cores, sizeof(int));
    pid_t pid;
    va_list args;

    /*
     * To forward variable arguments (variadic) to child function just get it from main argument and use va_start() and
     * va_end() finally send this argument to child function.
     * ! ! !ATTENTION: do NOT read args in parent function if you do it, variadic remove incoming data after reading those, and
     * you can NOT access those data in child function.
     * */
    va_start(args, argsNum);

    // The first index always should be 0 on shared memory to save produced chromosomes.
    defineStartIdx[0] = 0;

    // Define an array which contain the number of start index of each process on shared memory to save produced chromosomes.
    for (int i = 1; i < cores; i++)
        if (i <= remained)
            defineStartIdx[i] = ((childShare + 1) * chromosomeLen) + defineStartIdx[i - 1];
        else
            defineStartIdx[i] = (childShare * chromosomeLen) + defineStartIdx[i - 1];

    for (int i = 0; i < cores; i++) {

        // Make new process
        pid = fork();

        if (pid == -1) {
            printf("\nCreating new process has ERROR!\n");
            exit(1);
        }

        if (pid == 0) {

            // Current child process
            if (i < remained)
                (*subProcess)(chromosomeLen, childShare + 1, sharedMem, defineStartIdx[i], argsNum, args);
            else // Current child's parent process
                (*subProcess)(chromosomeLen, childShare, sharedMem, defineStartIdx[i], argsNum, args);

            // Exit each child process which finished their task
            exit(0);
        } else {
            // Use srand() for each process in order to produce random numbers per each process
            srand(clock() * getpid());
        }
    }

    // Wait for produced process to finish their tasks
    for (int i = 0; i < cores; i++) wait(NULL);

    va_end(args);

    free(defineStartIdx);
    return sharedMem;
}
