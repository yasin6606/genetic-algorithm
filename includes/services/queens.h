//
// Created by yasin on 9/21/23.
//

#ifndef GENETIC_ALGORITHM_QUEENS_H
#define GENETIC_ALGORITHM_QUEENS_H

void queensMain();

void evalQueens(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args);

int evalSolQueen(const int *sol, size_t size);

void queensPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                           va_list args);

#endif //GENETIC_ALGORITHM_QUEENS_H
