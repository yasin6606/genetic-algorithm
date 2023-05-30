//
// Created by yasin on 5/28/23.
//

#ifndef GENETIC_ALGORITHM_MAKERS_H
#define GENETIC_ALGORITHM_MAKERS_H

#include "./../functions/chromosomeMaker.c"
#include "./../functions/tweak.c"

int *chromosomeMaker(size_t n, bool isBin, bool isPerm);

void tweak(int *sol, size_t size);

#endif //GENETIC_ALGORITHM_MAKERS_H
