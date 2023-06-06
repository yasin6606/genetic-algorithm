#include "../../headers/sharedLib.h"

void evalQueens(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args);

int evalSolQueen(const int *sol, size_t size);

/*
 * To find diagonal collisions, just find differences between each queen's location (row, col) with other queens; If
 * differences are the same so these queens are met each other.
 * */
void evalQueens(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args) {
    int *matrix = va_arg(args,
    int*);

    for (int i = 0; i < childShare; i++)
        sharedMem[i + (startIdx / populationNum)] = evalSolQueen(&matrix[startIdx + (i * populationNum)],
                                                                 populationNum);

    va_end(args);
}

int evalSolQueen(const int *sol, size_t size) {
    int collision = 0, i = 0, j = i + 1;

    while (i < size - 2) {
        if (j >= size) {
            i++;
            j = i + 1;
        }

        if (abs(sol[i] - sol[j]) == abs(i - j))
            collision++;

        j++;
    }

    return collision;
}