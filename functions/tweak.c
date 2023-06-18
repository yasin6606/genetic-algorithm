#include "../headers/assistant.h"
#include "../headers/makers.h"

void tweak(int *population, size_t populationLen, size_t chromosomeLen) {
    int mutationPercent, *r = NULL, *rands = NULL;

    mutationPercent = ceil(populationLen * MUTATION_PERCENT);

    r = makePerm(populationLen, false, mutationPercent, 0);

    for (int i = 0; i < mutationPercent; i++) {
        rands = makePerm(chromosomeLen, false, 2, 0);

        swap(&population[r[i] * chromosomeLen], rands[0], rands[1]);
    }

    free(r);
    free(rands);
}