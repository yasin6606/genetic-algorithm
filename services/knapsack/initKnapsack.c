#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

int *makeKnapsackPopulation(size_t populationLen, size_t chromosomeLen) {
    int *chromosome = NULL, *population = (int *) calloc(populationLen * chromosomeLen, sizeof(int));

    for (int i = 0; i < populationLen; i++) {
        chromosome = makeBin(chromosomeLen);

        for (int j = 0; j < chromosomeLen; j++)
            population[(i * chromosomeLen) + j] = chromosome[j];

        free(chromosome);
    }

    return population;
}