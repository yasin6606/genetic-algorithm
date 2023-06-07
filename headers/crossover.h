//
// Created by yasin on 6/1/23.
//

#ifndef GENETIC_ALGORITHM_CROSSOVER_H
#define GENETIC_ALGORITHM_CROSSOVER_H

#include "../functions/crossover.c"

void crossover2P(int *firstParent, int *secondParent, size_t populationNum, bool ignorePerm, int *firstChild,
                 int *secondChild);

void crossoverUni(int *firstParent, int *secondParent, size_t populationNum, bool ignorePerm, int *firstChild,
                  int *secondChild);

#endif //GENETIC_ALGORITHM_CROSSOVER_H
