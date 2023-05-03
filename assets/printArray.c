#include "stdio.h"

void printArray(int size, int *arr, char *text) {
    puts("");
    printf("%s", text);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    puts("");
}