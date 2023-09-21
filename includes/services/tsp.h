//
// Created by yasin on 9/21/23.
//

#ifndef GENETIC_ALGORITHM_TSP_H
#define GENETIC_ALGORITHM_TSP_H

void tspMain();

// Make array of evaluation of population
void
evalTSPPopulation(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args);

void tspPopulationMaker(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                        va_list args);

void tspDisMaker(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                 va_list args);

#endif //GENETIC_ALGORITHM_TSP_H
