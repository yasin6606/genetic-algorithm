#include "../headers/sharedLib.h"
#include "../headers/assets.h"
#include "../types/GeneralTypes.h"

EvalType *bubbleSort(EvalType *arr, size_t len) {
    EvalType t;

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (arr[j].value < arr[j - 1].value) {
                t = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = t;
            }

    return arr;
}

void *sortChromosomes(int *evalArr, size_t len) {
    EvalType *eval = (EvalType *) calloc(len, sizeof(EvalType));

    for (int i = 0; i < len; i++) {
        eval[i].idx = i;
        eval[i].value = evalArr[i];
    }

    // Sorting
    eval = bubbleSort(eval, len);

    return eval;
}