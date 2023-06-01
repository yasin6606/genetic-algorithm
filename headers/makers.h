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

int *makeBin(size_t n);

int *makePerm(size_t n, bool ignorePerm, size_t limitLen);

void tweak(int *sol, size_t size);

void *parentSelection(void *evaluationArr, size_t populationNum, bool type);

#endif //GENETIC_ALGORITHM_MAKERS_H