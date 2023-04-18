#include "../headers/mainHeaders.h"

void printMatrix(int dimension, int *matrix) {
    puts("");
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%d  ", matrix[i * dimension + j]);
        }
        puts("");
    }
    puts("");
}