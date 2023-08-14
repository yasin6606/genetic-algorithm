#include "../headers/sharedLib.h"
#include "../headers/printing.h"

void *arraySharedMemory(size_t nSize, size_t size) {
    void *mem = NULL;
    int protection = PROT_READ | PROT_WRITE, visibility = MAP_SHARED | MAP_ANONYMOUS;

    mem = mmap(NULL, nSize * size, protection, visibility, -1, 0);

    if (mem == MAP_FAILED) {
        perror("mmap Error!");
        exit(EXIT_FAILURE);
    }

//    printArray(nSize, mem, "mem: ", ANSI_COLOR_RESET);

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
