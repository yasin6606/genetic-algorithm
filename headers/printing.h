//
// Created by yasin on 5/28/23.
//

#ifndef GENETIC_ALGORITHM_PRINTING_H
#define GENETIC_ALGORITHM_PRINTING_H

#include "./../assets/printArray.c"
#include "./../assets/printMatrix.c"


void printArray(size_t size, const int *arr, char *text, char *color);

void printMatrix(size_t dimension, int *matrix, bool showRowIdx);

#endif //GENETIC_ALGORITHM_PRINTING_H
