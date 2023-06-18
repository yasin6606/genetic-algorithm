#include "../headers/assets.h"
#include "../headers/makers.h"

void tweak(int *population, size_t populationNum, size_t populationLen) {
    int mutationPercent, *r = NULL, *rands = NULL;

    mutationPercent = ceil(populationLen * MUTATION_PERCENT);

    r = chromosomeMaker(populationLen, false, true, mutationPercent, 0);

    for (int i = 0; i < mutationPercent; i++) {
        rands = chromosomeMaker(populationNum, false, true, 2, 0);

        swap(&population[r[i] * populationNum], rands[0], rands[1]);
    }

    free(r);
    free(rands);
}