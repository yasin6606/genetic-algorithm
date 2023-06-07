#include "../headers/assets.h"
#include "../headers/makers.h"

void tweak(int *sol, size_t populationNum) {
    int *rands = chromosomeMaker(populationNum, false, true, 2, 0);

    swap(sol, rands[0], rands[1]);
}