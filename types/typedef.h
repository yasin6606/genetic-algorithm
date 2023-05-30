//
// Created by yasin on 5/29/23.
//

#ifndef GENETIC_ALGORITHM_TYPEDEF_H
#define GENETIC_ALGORITHM_TYPEDEF_H

#include "../headers/sharedLib.h"

typedef int *(*chromosome_producer_t)(size_t n);

typedef int *(*chromosome_evaluator_t)(size_t n);

typedef void (*sub_process_t)(size_t populationNum, size_t childShare, int *sharedMem, int startIdx);

#endif //GENETIC_ALGORITHM_TYPEDEF_H
