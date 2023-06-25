#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

void knapsackPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                             va_list args) {
    int *tempChromosome = NULL;

    for (int i = 0; i < childShare; i++) {

        // Produce a BINARY chromosome
        tempChromosome = chromosomeMaker(populationNum, true, false, -1, 0);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[startIdx + j] = tempChromosome[j];

        startIdx = startIdx + populationNum;

        free(tempChromosome);
    }

    va_end(args);
}