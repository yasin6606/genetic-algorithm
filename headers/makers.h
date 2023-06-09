//
// Created by yasin on 5/31/23.
//

#ifndef GENETIC_ALGORITHM_MAKERS_H
#define GENETIC_ALGORITHM_MAKERS_H

#include <stdlib.h>
#include "../functions/makeBin.c"
#include "../functions/makePerm.c"
#include "../functions/tweak.c"
#include "../functions/parentSelection.c"
#include "../functions/breakPointGenerator.c"
#include "../functions/childGenerator.c"
#include "../functions/crossover.c"

int *makeBin(size_t n);

int *makePerm(size_t n, bool ignorePerm, size_t limitLen, size_t ignoredNumsCount, ...);

void tweak(int *population, size_t populationLen, size_t chromosomeLen);

void *parentSelection(void *evaluationArr, size_t populationNum, bool type);

int *breakPointGenerator(size_t populationNum);

int *childGenerator2P(size_t populationNum, bool ignorePerm, int *breakPoints, int *oneParent, int *anotherParent);

int *childGeneratorUni(size_t populationNum, bool ignorePerm, int *mask, int *oneParent, int *anotherParent);

void *crossover(size_t populationLen, size_t chromosomeLen, int *population, int eliteNum, int *evalSortedIdx,
                int *evalArr, bool type, bool ignorePerm, int crossoverType);

#endif //GENETIC_ALGORITHM_MAKERS_H