#include "../../headers/sharedLib.h"

// make array of evaluation of DIS matrix
int *evalTSP(const int *matrix, size_t size) {
    int row, col, sum, *tempArr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++) {
        sum = 0;

        for (int j = 0; j < size - 1; j++) {
            // get row of each sol
            row = matrix[i * size + j];

            // get col of each sol
            col = matrix[i * size + j + 1];

            sum += matrix[row * size + col];
        }

        sum += matrix[(size - 1) * size];

        tempArr[i] = sum;
    }

    return tempArr;
}