//
// Created by yasin on 5/29/23.
//

#ifndef GENETIC_ALGORITHM_SHAREDMEMORY_H
#define GENETIC_ALGORITHM_SHAREDMEMORY_H

void *arraySharedMemory(size_t nSize, size_t size);

void *varSharedMemory(size_t size);

void memoryUnmap(void *address, size_t len, size_t sizeType);

#endif //GENETIC_ALGORITHM_SHAREDMEMORY_H
