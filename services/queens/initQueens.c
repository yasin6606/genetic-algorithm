#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

void queensPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                           va_list args) {
    int *tempChromosome = NULL;

    for (int i = 0; i < childShare; i++) {

        // Produce a chromosome
        tempChromosome = chromosomeMaker(populationNum, false, true, -1, 0, NULL);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[startIdx + (i * populationNum) + j] = tempChromosome[j];

        free(tempChromosome);
    }

    va_end(args);
}