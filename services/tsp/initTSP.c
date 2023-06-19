#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"
#include "../../headers/printing.h"

void tspPopulationMaker(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                        va_list args) {
    int *tempChromosome = NULL;

    for (int i = 0; i < childShare; i++) {

        // Produce a chromosome
        tempChromosome = chromosomeMaker(chromosomeLen, false, true, -1, 0);

        // Add chromosome to shared memory
        for (int j = 0; j < chromosomeLen; j++)
            sharedMem[startIdx + (i * chromosomeLen) + j] = tempChromosome[j];

        free(tempChromosome);
    }

    va_end(args);
}

void tspDisMaker(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                 va_list args) {
    int *tempChromosome = NULL, elemIdx;

    for (int i = 0; i < childShare; i++) {

        // Find the element on main diameter on each chromosome.
        elemIdx = (startIdx / chromosomeLen) + i;

        // Produce a chromosome
        tempChromosome = chromosomeMaker(chromosomeLen, false, true, -1, 0);

        // make main diameter zero (moving non-zero elements on main diameter to zero element)
        for (int j = 0; j < chromosomeLen; j++) {
            if (tempChromosome[elemIdx] == 0) continue;

            // tempChromosome[elemIdx] == element on main diameter | tempChromosome[j] == zero element
            if (tempChromosome[j] == 0)
                swap(tempChromosome, j, elemIdx);
        }

        // Add chromosome to shared memory
        for (int j = 0; j < chromosomeLen; j++)
            sharedMem[startIdx + (i * chromosomeLen) + j] = tempChromosome[j];

        free(tempChromosome);
    }

    va_end(args);
}