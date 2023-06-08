#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void printMatrix(size_t dimension, int *matrix, bool showRowIdx) {
    puts("");

    for (int i = 0; i < dimension; i++) {
        if (showRowIdx)
            printf("%d %s|%s\t", i, ANSI_COLOR_RED, ANSI_COLOR_RESET);

        for (int j = 0; j < dimension; j++)
            printf("%d\t", matrix[i * dimension + j]);

        puts("");
    }

    fflush(stdout);
    puts("");
}