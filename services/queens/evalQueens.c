#include "../../headers/sharedLib.h"

int *evalQueens(const int *matrix, size_t size);

int evalSolQueen(const int *sol, size_t size);

/*
 * To find diagonal collisions, just find differences between each queen's location (row, col) with other queens; If
 * differences are the same so these queens are met each other.
 * */
int *evalQueens(const int *matrix, size_t size) {
    int *tempArr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
        tempArr[i] = evalSolQueen(&matrix[i * size], size);

    return tempArr;
}

//// O(n) new method
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

//// O(n^2) old method
//int evalSolQueen(const int *sol, size_t size) {
//    int collision = 0;
//
//    for (int i = 0; i < size - 1; i++)
//        for (int j = i; j < size - 1; j++)
//            if (abs(sol[i] - sol[j + 1]) == abs(i - (j + 1)))
//                collision++;
//
//    return collision;
//}