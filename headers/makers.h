//
// Created by yasin on 5/28/23.
//

#ifndef GENETIC_ALGORITHM_MAKERS_H
#define GENETIC_ALGORITHM_MAKERS_H

#include "../functions/chromosomeMaker.c"
#include "../functions/tweak.c"
#include "../functions/breakPointGenerator.c"
#include "../functions/childGenerator.c"
#include "../functions/parentSelection.c"

int *chromosomeMaker(size_t maxGenNum, bool isBin, bool isPerm, int limitLen, size_t ignoreNumsCount, ...);

void tweak(int *sol, size_t size);

int *breakPointGenerator(size_t populationNum);

int *childGenerator2P(size_t populationNum, int *breakPoints, bool ignorePerm, int *oneParent, int *anotherParent);

int *childGeneratorUni(size_t populationNum, bool ignorePerm, int *mask, int *oneParent, int *anotherParent);

void *parentSelection(void *evaluationArr, size_t populationNum, bool type);


#endif //GENETIC_ALGORITHM_MAKERS_H
