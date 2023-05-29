//
// Created by yasin on 5/29/23.
//

#ifndef GENETIC_ALGORITHM_CHROMOSOMEMP_H
#define GENETIC_ALGORITHM_CHROMOSOMEMP_H

#include "../../headers/sharedLib.h"
#include "../../types/typedef.h"
#include "../../functions/multiprocessing/chromosomeMP.c"

void chromosomeMP(size_t populationNum, chromosome_producer_t producer);

#endif //GENETIC_ALGORITHM_CHROMOSOMEMP_H
