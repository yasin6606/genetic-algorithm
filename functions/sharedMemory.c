#include "../headers/sharedLib.h"

void *arraySharedMemory(size_t nSize, size_t size) {
    void *mem = NULL;
    int protection = PROT_READ | PROT_WRITE, visibility = MAP_SHARED | MAP_ANONYMOUS;

    mem = mmap(NULL, nSize * size, protection, visibility, -1, 0);

    if (mem == MAP_FAILED) {
        perror("mmap Error!");
        exit(EXIT_FAILURE);
    }

    return mem;
}

void *varSharedMemory(size_t size) {
    void *mem = NULL;
    int protection = PROT_READ | PROT_WRITE, visibility = MAP_SHARED | MAP_ANONYMOUS;

    mem = mmap(NULL, 1 * size, protection, visibility, -1, 0);

    if (mem == MAP_FAILED) {
        perror("mmap Error!");
        exit(EXIT_FAILURE);
    }

    return mem;
}
