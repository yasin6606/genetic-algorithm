//
// Created by yasin on 5/28/23.
//

#ifndef GENETIC_ALGORITHM_ASSETS_H
#define GENETIC_ALGORITHM_ASSETS_H

#include "./../assets/max.c"
#include "./../assets/swap.c"
#include "./../assets/sortChromosomes.c"
#include "./../assets/reverseArray.c"
#include "./../assets/hideSameValue.c"

int max(const int *arr, size_t size);

void swap(int *arr, size_t firstIdx, size_t secondIdx);

void *sortChromosomes(int *evalArr, size_t len);

void reverseArray(void *arr, size_t len);

void hideSameValue(int *arr, int *len);

#endif //GENETIC_ALGORITHM_ASSETS_H