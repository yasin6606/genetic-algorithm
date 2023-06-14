#include "../headers/assets.h"
#include "../headers/makers.h"

void tweak(int *population, size_t populationNum) {
    int mutationPercent, *rands = NULL;

    mutationPercent = ceil(populationNum * MUTATION_PERCENT);

    for (int i = 0; i < mutationPercent; i++) {
        rands = chromosomeMaker(populationNum, false, true, 2, 0);

        swap(&population[i * populationNum], rands[0], rands[1]);
    }
}