#include "../includes/sharedLib.h"
#include "../includes/assets.h"

void reverseArray(void *arr, size_t len) {
    for (int i = 0; i < len / 2; i++)
        swap(arr, i, len - 1 - i);
}