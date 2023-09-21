//
// Created by yasin on 5/29/23.
//

#ifndef GENETIC_ALGORITHM_MULTIPROCESSOR_H
#define GENETIC_ALGORITHM_MULTIPROCESSOR_H

#include "./../types/functionTypedef.h"

void *
multiprocessor(size_t tasks, size_t chromosomeLen, size_t sharedMemLen, size_t memSizeType, sub_process_t subProcess,
               size_t argsNum, ...);

#endif //GENETIC_ALGORITHM_MULTIPROCESSOR_H
