//
// Created by yasin on 5/28/23.
//

#ifndef GENETIC_ALGORITHM_MAKERS_H
#define GENETIC_ALGORITHM_MAKERS_H

int *chromosomeMaker(size_t maxGenNum, bool isBin, bool isPerm, int limitLen, size_t ignoreNumbersLen,
                     int *ignoreNumbersArr);

void tweak(int *population, size_t chromosomeLen, size_t populationLen, size_t eliteLen);

int *breakPointGenerator(size_t populationNum);

int *childGenerator2P(size_t populationNum, bool ignorePerm, int *breakPoints, int *oneParent, int *anotherParent);

int *childGeneratorUni(size_t populationNum, bool ignorePerm, int *mask, int *oneParent, int *anotherParent);

void *parentSelection(void *evaluationArr, size_t populationNum, bool type);

void crossover(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args);

#endif //GENETIC_ALGORITHM_MAKERS_H
