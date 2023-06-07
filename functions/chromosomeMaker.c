#include "../headers/sharedLib.h"

int *chromosomeMaker(size_t maxGenNum, bool isBin, bool isPerm, int limitLen, size_t ignoreNumsCount, ...) {
    int len = maxGenNum, num, j, temp, *arr = NULL, *flag = NULL, *ignoredNumsFlag = NULL;

    // Check so as to generate Binary chromosomes
    if (isBin)
        isPerm = false;

    // Check chromosome length limitation
    if (limitLen != -1)
        len = limitLen;

    arr = (int *) calloc(len, sizeof(int));

    /*
     * Check if some numbers must be ignored.
     * Attention ! Using this condition in order to avoid reading this scope of code whereas ignoredNumsCount is zero.
    */
    if (ignoreNumsCount > 0) {
        ignoredNumsFlag = (int *) calloc(maxGenNum, sizeof(int));

        // Variadic ! These number must be ignored on generated chromosome
        va_list ignoredNumsArgs;

        va_start(ignoredNumsArgs, ignoreNumsCount);

        for (int i = 0; i < ignoreNumsCount; i++) {
            temp = va_arg(ignoredNumsArgs,
            int);

            // Make income gens ignored
            ignoredNumsFlag[temp] = 1;
        }

        va_end(ignoredNumsArgs);
    }

    for (int i = 0; i < len; i++) {
        // re-empty flags
        flag = (int *) calloc(maxGenNum, sizeof(int));

        j = 0;

        do {
            if (isBin) // Generate BINARY gen
                num = rand() % 2;
            else // Generate PERMUTATION gen
                num = rand() % maxGenNum;

            // Prevent adding ignored gens (numbers) if they are generated
            if (ignoreNumsCount > 0 && ignoredNumsFlag[num] == 1) continue;

            // Check flag array in order to generate PERMUTATION chromosome
            if (isPerm && flag[num] == 1) continue;

            arr[j] = num;

            if (isPerm)
                flag[num] = 1;

            j++;
        } while (j < len);

        // free last used space for flags array (! It is IMPORTANT to avoid Memory Leak)
        free(flag);
    }

    // free last used space for flags array (! It is IMPORTANT to avoid Memory Leak)
    free(ignoredNumsFlag);

    return arr;
}