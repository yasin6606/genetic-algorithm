#include "../headers/sharedLib.h"

void printMatrix(size_t dimension, int *matrix, bool showRowIdx) {
    puts("");

    for (int i = 0; i < dimension; i++) {
        if (showRowIdx)
            printf("%d |\t", i);

        for (int j = 0; j < dimension; j++)
            printf("%d\t", matrix[i * dimension + j]);

        puts("");
    }

    puts("");
}