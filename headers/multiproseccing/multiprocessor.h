//
// Created by yasin on 5/29/23.
//

#ifndef GENETIC_ALGORITHM_MULTIPROCESSOR_H
#define GENETIC_ALGORITHM_MULTIPROCESSOR_H

#include "../../headers/sharedLib.h"
#include "../../types/functionTypedef.h"
#include "../../functions/multiprocessing/multiprocessor.c"

void *multiprocessor(size_t tasks, size_t chromosomeLen, size_t sharedMemLen, sub_process_t subProcess, size_t argsNum, ...);

#endif //GENETIC_ALGORITHM_MULTIPROCESSOR_H
