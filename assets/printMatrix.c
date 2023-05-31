#include "../headers/sharedLib.h"

void printMatrix(size_t dimension, int *matrix) {
    puts("");

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++)
            printf("%d\t", matrix[i * dimension + j]);

        puts("");
    }

    puts("");
}