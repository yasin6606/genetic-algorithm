#include "../includes/sharedLib.h"
#include "../includes/sharedMacros.h"

void hideSameValue(int *arr, int *len) {
    for (int i = *len - 1; i > 0; i--)
        if (arr[i] != arr[i - 1]) {
            *len = i + MORE_SAME_RESULT_NUM;

            // To decrease solution array's length
            arr = (int *) realloc(arr, *len * sizeof(int));

            break;
        }
}