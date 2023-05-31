//
// Created by yasin on 5/31/23.
//

#ifndef GENETIC_ALGORITHM_PRINTING_H
#define GENETIC_ALGORITHM_PRINTING_H

#include <stdlib.h>
#include "../assets/printArray.c"
#include "../assets/printMatrix.c"


void printArray(size_t size, const int *arr, char *text);

void printMatrix(size_t dimension, int *matrix);

#endif //GENETIC_ALGORITHM_PRINTING_H