//
// Created by yasin on 5/29/23.
//

#ifndef GENETIC_ALGORITHM_SHAREDMEMORY_H
#define GENETIC_ALGORITHM_SHAREDMEMORY_H

#include "../headers/sharedLib.h"
#include "../functions/sharedMemory.c"

void *arraySharedMemory(size_t nSize, size_t size);

void *varSharedMemory(size_t size);

#endif //GENETIC_ALGORITHM_SHAREDMEMORY_H
