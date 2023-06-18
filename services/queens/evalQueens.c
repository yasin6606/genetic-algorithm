#include "../../headers/sharedLib.h"

int *evalQueens(const int *population, size_t populationLen, size_t chromosomeLen);

int evalSolQueen(const int *sol, size_t len);

/*
 * To find diagonal collisions, just find differences between each queen's location (row, col) with other queens; If
 * differences are the same so these queens are met each other.
 * */

int *evalQueens(const int *population, size_t populationLen, size_t chromosomeLen) {
    int *tempArr = (int *) calloc(populationLen, sizeof(int));

    for (int i = 0; i < populationLen; i++)
        tempArr[i] = evalSolQueen(&population[i * chromosomeLen], chromosomeLen);

    return tempArr;
}

int evalSolQueen(const int *sol, size_t len) {
    int collision = 0, i = 0, j = i + 1;

    while (i < len - 2) {
        if (j >= len) {
            i++;
            j = i + 1;
        }

        if (abs(sol[i] - sol[j]) == abs(i - j))
            collision++;

        j++;
    }

    return collision;
}