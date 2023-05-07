#include "../headers/mainHeaders.h"
#include "time.h"

int *makePerm(size_t n) {
    int num, j;
    int *arr = (int *) calloc(n * n, sizeof(int));
    int *flag = NULL;

    for (int i = 0; i < n; i++) {
        // re-empty flags
        flag = (int *) calloc(n * n, sizeof(int));
        j = 0;

        do {
            num = rand() % n;

            if (flag[num] == 1) continue;

            arr[j] = num;
            flag[num] = 1;

            j++;
        } while (j < n);

        // free last used space for flag array
        free(flag);
    }

    return arr;
}
