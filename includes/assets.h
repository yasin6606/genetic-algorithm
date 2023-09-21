//
// Created by yasin on 5/28/23.
//

#ifndef GENETIC_ALGORITHM_ASSETS_H
#define GENETIC_ALGORITHM_ASSETS_H

#include "sharedLib.h"

int max(const int *arr, size_t size);

void swap(int *arr, size_t firstIdx, size_t secondIdx);

void *sortChromosomes(int *evalArr, size_t len);

void reverseArray(void *arr, size_t len);

void hideSameValue(int *arr, int *len);

void livePrinter(char *text, int start, char *textColor, char *digitColor, bool keepLine);

#endif //GENETIC_ALGORITHM_ASSETS_H