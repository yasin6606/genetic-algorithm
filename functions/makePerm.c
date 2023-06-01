#include "../headers/sharedLib.h"
#include "../headers/printing.h"

int *makePerm(size_t n, bool ignorePerm, size_t limitLen, size_t ignoreNumsCount, ...) {
    int num, j, len, *arr = (int *) calloc(n, sizeof(int)), *flag = NULL,
            *ignoredNumsArr = (int *) calloc(ignoreNumsCount, sizeof(int));

    len = n;

    if (limitLen != -1) {
        len = limitLen;
        arr = (int *) reallocarray(arr, limitLen, sizeof(int));
    }

    // Attention ! Using this condition in order to avoid reading this scope of code when ignoredNumsCount is zero.
    if (ignoreNumsCount > 0) {
        // Variadic ! These number must be ignored on generated chromosome
        va_list ignoredNumsArgs;

        va_start(ignoredNumsArgs, ignoreNumsCount);

        for (int i = 0; i < ignoreNumsCount; i++)
            ignoredNumsArr[i] = va_arg(ignoredNumsArgs,
        int);

        printArray(ignoreNumsCount, ignoredNumsArr, "A ");

        va_end(ignoredNumsArgs);
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
