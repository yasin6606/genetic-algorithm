#include "../../headers/sharedLib.h"
#include "../../types/typedef.h"
#include "../../headers/sharedMemory.h"

void *chromosomeMP(size_t populationNum, sub_process_t subProcess) {
    void *sharedMem = arraySharedMemory(populationNum * populationNum, sizeof(void *));
    int cores = get_nprocs(), childShare = floor(populationNum / cores), remained = populationNum % cores,
            *defineStartIdx = (int *) calloc(cores, sizeof(int));
    pid_t pid;

    // The first index always should be 0 on shared memory to save produced chromosomes.
    defineStartIdx[0] = 0;

    // Define an array which contain the number of start index of each process on shared memory to save produced chromosomes.
    for (int i = 1; i < cores; i++)
        if (i <= remained)
            defineStartIdx[i] = ((childShare + 1) * populationNum) + defineStartIdx[i - 1];
        else
            defineStartIdx[i] = (childShare * populationNum) + defineStartIdx[i - 1];

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
                (*subProcess)(populationNum, childShare + 1, sharedMem, defineStartIdx[i]);
            else // Current child's parent process
                (*subProcess)(populationNum, childShare, sharedMem, defineStartIdx[i]);

            // Exit each child process which finished their task
            exit(0);
        } else {
            // Use srand for each process in order to produce random numbers per each process
            srand(clock());
        }
    }

    // Wait for produced process to finish their tasks
    for (int i = 0; i < cores; i++) wait(NULL);

    return sharedMem;
}
