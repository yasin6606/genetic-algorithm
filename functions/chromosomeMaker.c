#include "../headers/sharedLib.h"

int *chromosomeMaker(size_t n, bool isBin, bool isPerm) {
    int num, j;
    int *arr = (int *) calloc(n, sizeof(int));
    int *flag = NULL;

    if (isBin)
        isPerm = false;

    for (int i = 0; i < n; i++) {
        // re-empty flags
        if (isPerm)
            flag = (int *) calloc(n, sizeof(int));

        j = 0;

        do {
            if (isBin)
                num = rand() % 2;
            else
                num = rand() % n;

            if (isPerm && flag[num] == 1) continue;

            arr[j] = num;

            if (isPerm)
                flag[num] = 1;

            j++;
        } while (j < n);

        // free last used space for flag array
        free(flag);
    }

    return arr;
}