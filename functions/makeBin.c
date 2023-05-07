#include "../headers/mainHeaders.h"

int *makeBin(size_t n) {
    int *arr = (int *) calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 2; // (% 2) is to create binary value

    return arr;
}