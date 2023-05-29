#include "../../headers/sharedLib.h"
#include "../../types/typedef.h"
#include "../../headers/sharedMemory.h"

void
subProcess(size_t populationNum, size_t childShare, int *sharedMem, chromosome_producer_t producer, int *startIdx) {
    int *tempChromosome;

    for (int i = 0; i < childShare; i++) {

        // Produce a chromosome
        tempChromosome = (*producer)(populationNum);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[*startIdx + j] = tempChromosome[j];

        *startIdx = *startIdx + populationNum;

        free(tempChromosome);
    }
}

void *chromosomeMP(size_t populationNum, chromosome_producer_t producer) {
    void *sharedMem = arraySharedMemory(populationNum * populationNum, sizeof(void *));
    int cores = get_nprocs(), childShare = floor(populationNum / cores), remained = populationNum % cores,
            *startIdx = varSharedMemory(sizeof(int));
    pid_t pid;

    *startIdx = 0;

    for (int i = 0; i < cores; i++) {

        // Make new process
        pid = fork();

        if (pid == 0) {

            // Current child process
            if (i < remained)
                subProcess(populationNum, childShare + 1, sharedMem, producer, startIdx);
            else // Current child's parent process
                subProcess(populationNum, childShare, sharedMem, producer, startIdx);

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
