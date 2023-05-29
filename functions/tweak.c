#include "../headers/assets.h"

void tweak(int *sol, size_t size) {
    int rand1 = rand() % size, rand2 = rand() % size;

    //// Maybe here we need to use sleep() to make a different random numbers when tweak() calls continually

    swap(sol, rand1, rand2);
}