#include "sys/mman.h"

void *arraySharedMemory(size_t nSize, size_t size) {
    int *mem, protection = PROT_READ | PROT_WRITE, visibility = MAP_SHARED | MAP_ANONYMOUS;

    mem = mmap(NULL, nSize * size, protection, visibility, -1, 0);

    // make default values -1. When each value is -1, so it means this element of array is not modified (is empty)
    for (int i = 0; i < nSize; i++)
        mem[i] = -1;

    return mem;
}

void *varSharedMemory(size_t size) {
    void *mem;
    int protection = PROT_READ | PROT_WRITE, visibility = MAP_SHARED | MAP_ANONYMOUS;

    mem = mmap(NULL, 1 * size, protection, visibility, -1, 0);

    return mem;
}
