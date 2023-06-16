#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void printMatrix(size_t dimension, int *matrix, bool showRowIdx) {
    puts("");

    for (int i = 0; i < dimension; i++) {
        if (showRowIdx)
            printf("%3d %s|%5s", i, ANSI_COLOR_RED, ANSI_COLOR_RESET);

        for (int j = 0; j < dimension; j++)
            printf("%4d", matrix[i * dimension + j]);

        puts("");
    }

    fflush(stdout);
    puts("");
}