#include "../../headers/sharedLib.h"
#include "../../headers/assistant.h"
#include "../../headers/makers.h"
#include "../../headers/printing.h"

int *tspPopulationMaker(size_t populationLen, size_t chromosomeLen) {
    int *arr = (int *) calloc(populationLen * chromosomeLen, sizeof(int)), *chromosome = NULL;

    for (int i = 0; i < populationLen; i++) {

        // Produce a chromosome
        chromosome = makePerm(chromosomeLen, false, -1, 0);

        // Add produced chromosome to the population
        for (int j = 0; j < chromosomeLen; j++)
            arr[(i * chromosomeLen) + j] = chromosome[j];

        free(chromosome);
    }

    return arr;
}

int *tspDisMaker(size_t chromosomeLen) {
    int *disArr = (int *) calloc(chromosomeLen * chromosomeLen, sizeof(int)), *randArr = NULL;

    for (int i = 0; i < chromosomeLen; i++) {
        randArr = makePerm(chromosomeLen, false, -1, 0);

        // Make main diameter zero (moving non-zero elements on main diameter to zero element)
        for (int j = 0; j < chromosomeLen; j++) {
            if (randArr[i] == 0) continue;

            // randArr[i] == element on main diameter | randArr[j] == zero element
            if (randArr[j] == 0)
                swap(randArr, j, i);
        }

        // make DIS matrix
        for (int j = 0; j < chromosomeLen; j++)
            disArr[i * chromosomeLen + j] = randArr[j];

        free(randArr);
    }

    return disArr;
}