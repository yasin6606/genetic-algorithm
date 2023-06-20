#include "../../headers/sharedLib.h"

// Make array of evaluation of population
int *evalTSPPopulation(size_t populationLen, size_t chromosomeLen, int *disMatrix, int *population) {
    int sum, *sol = NULL, *arr = (int *) calloc(populationLen, sizeof(int)), row, col;

    for (int i = 0; i < populationLen; i++) {
        sum = 0;

        // Each chromosome
        sol = &population[i * chromosomeLen];

        // Select row and col on DIS matrix
        for (int j = 0; j < chromosomeLen - 1; j++)
            sum += disMatrix[(sol[j] * chromosomeLen) + sol[j + 1]];

        // Finally, return hometown
        sum += disMatrix[(sol[chromosomeLen - 1] * chromosomeLen) + sol[0]];

        arr[i] = sum;
    }

    return arr;
}