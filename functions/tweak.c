#include "../headers/assistant.h"
#include "../headers/makers.h"

// Make a mutation
void tweak(int *sol, size_t size) {
    int *rands = makePerm(size, false, 2, 0);

    swap(sol, rands[0], rands[1]);
}