#include "../headers/sharedLib.h"
#include "../headers/makers.h"

void *c(size_t populationLen, size_t chromosomeLen, int *population, int eliteNum, int *evalSortedIdx, int *evalArr, bool type,
        bool ignorePerm, int crossoverType) {
    int *newPopulation = (int *) calloc(chromosomeLen * chromosomeLen, sizeof(int)), *p1 = NULL, *p2 = NULL,
            *bestParents = NULL, *newChild = NULL, *breakPoints = NULL, *mask = NULL;

    for (int i = 0; i < populationLen; i++) {

        //// Directly move elites to new population
        if (i < eliteNum) {
            for (int j = 0; j < chromosomeLen; j++)
                newPopulation[(i * chromosomeLen) + j] = population[(evalSortedIdx[i] * chromosomeLen) + j];

            continue;
        }

        //// Produce the rest of new population

        bestParents = parentSelection(evalArr, chromosomeLen, type);
        p1 = &population[bestParents[0] * chromosomeLen];
        p2 = &population[bestParents[1] * chromosomeLen];

        if (crossoverType == 1) { // Two breaking points
            breakPoints = breakPointGenerator(chromosomeLen);

//            printf("P: %d, %d, -- B: %d, %d\n", bestParents[0], bestParents[1], breakPoints[0], breakPoints[1]);

//            newChild = childGenerator2P(chromosomeLen, ignorePerm, breakPoints, p1, p2);
            newChild = childG(chromosomeLen, breakPoints, p1, p2);

            free(breakPoints);
        } else { // Uniform
            mask = makeBin(chromosomeLen);

            newChild = childGeneratorUni(chromosomeLen, ignorePerm, mask, p1, p2);

            free(mask);
        }

        // Add the new child to new population
        for (int j = 0; j < chromosomeLen; j++)
            newPopulation[(i * chromosomeLen) + j] = newChild[j];

        free(newChild);
    }

    return newPopulation;
}