#include "../includes/assets.h"
#include "../includes/sharedMacros.h"
#include "../includes/makers.h"

void tweak(int *population, size_t chromosomeLen, size_t populationLen, size_t eliteLen) {
    int mutationPercent, *r = NULL, *rands = NULL, *ignoreElitesArr = NULL;

    mutationPercent = ceil(populationLen * MUTATION_PERCENT);

    // Make an array to avoid mutation on elites chromosomes
    if (eliteLen > 0) {
        ignoreElitesArr = (int *) calloc(eliteLen, sizeof(int));

        for (int i = 0; i < eliteLen; i++)
            ignoreElitesArr[i] = i;
    }

    // Make a random array by the length equal to mutationPercent so as to mutate on the population
    r = chromosomeMaker(populationLen, false, true, mutationPercent, eliteLen, ignoreElitesArr);

    for (int i = 0; i < mutationPercent; i++) {

        // Make two random number in order to mutate the chromosome
        rands = chromosomeMaker(chromosomeLen, false, true, TWO_LEN, 0, NULL);

        swap(&population[r[i] * chromosomeLen], rands[0], rands[1]);

        free(rands);
    }

    free(r);
}