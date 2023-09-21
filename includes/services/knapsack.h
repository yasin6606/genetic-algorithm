//
// Created by yasin on 9/21/23.
//

#ifndef GENETIC_ALGORITHM_KNAPSACK_H
#define GENETIC_ALGORITHM_KNAPSACK_H

void knapsackMain();

// make array of evaluation of Sol matrix
void evalKnapsack(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args);

// evaluate each Sol
int evalSolKnapsack(const int *sol, size_t populationNum, size_t wMax, int *wArr, int *vArr);

void knapsackPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                             va_list args);

#endif //GENETIC_ALGORITHM_KNAPSACK_H
