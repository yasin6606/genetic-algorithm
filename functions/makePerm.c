#include "../headers/sharedLib.h"

int *makePerm(size_t n, bool ignorePerm, size_t limitLen) {
    int num, j, len;
    int *arr = (int *) calloc(n, sizeof(int));
    int *flag = NULL;

    len = n;

    if (limitLen != -1) {
        len = limitLen;
        arr = (int *) reallocarray(arr, limitLen, sizeof(int));
    }

    for (int i = 0; i < len; i++) {
        // re-empty flags
        flag = (int *) calloc(n, sizeof(int));
        j = 0;

        do {
            num = rand() % n;

            if (!ignorePerm && flag[num] == 1) continue;

            arr[j] = num;
            flag[num] = 1;

            j++;
        } while (j < len);

        // free last used space for flag array
        free(flag);
    }

    return arr;
}
