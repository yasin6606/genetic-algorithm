#include "../headers/sharedLib.h"
#include "../headers/makers.h"

void *c(size_t tasks, size_t populationNum, int *population, int eliteNum, int *evalSortedIdx, int *evalArr, bool type,
        bool ignorePerm, int crossoverType) {
    int *newPopulation = (int *) calloc(populationNum * populationNum, sizeof(int)), *p1 = NULL, *p2 = NULL,
            *bestParents = NULL, *newChild = NULL, *breakPoints = NULL, *mask = NULL;

    for (int i = 0; i < tasks; i++) {

        //// Directly move elites to new population
        if (i < eliteNum) {
            for (int j = 0; j < populationNum; j++)
                newPopulation[(i * populationNum) + j] = population[(evalSortedIdx[i] * populationNum) + j];

            continue;
        }

        //// Produce the rest of new population

        bestParents = parentSelection(evalArr, populationNum, type);
        p1 = &population[bestParents[0] * populationNum];
        p2 = &population[bestParents[1] * populationNum];

        if (crossoverType == 1) { // Two breaking points
            breakPoints = breakPointGenerator(populationNum);

            printf("P: %d, %d, -- B: %d, %d\n", bestParents[0], bestParents[1], breakPoints[0], breakPoints[1]);

//            newChild = childGenerator2P(populationNum, ignorePerm, breakPoints, p1, p2);
            newChild = childG(populationNum, breakPoints, p1, p2);

            free(breakPoints);
        } else { // Uniform
            mask = makeBin(populationNum);

            newChild = childGeneratorUni(populationNum, ignorePerm, mask, p1, p2);

            free(mask);
        }

        // Add the new child to new population
        for (int j = 0; j < populationNum; j++)
            newPopulation[(i * populationNum) + j] = newChild[j];

        free(newChild);
    }

    return newPopulation;
}