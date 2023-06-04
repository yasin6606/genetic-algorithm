#include "../../headers/sharedLib.h"
#include "../../headers/assistant.h"
#include "../../headers/makers.h"

int *setDisSol(size_t n) {
    int *disArr = (int *) calloc(n * n, sizeof(int));
    int *randArr = NULL;

    for (int i = 0; i < n; i++) {
        randArr = makePerm(n, false, -1, 0);

        // make main diameter zero (moving non-zero elements on main diameter to zero element)
        for (int j = 0; j < n; j++) {
            if (randArr[i] == 0) continue;

            // randArr[i] == element on main diameter | randArr[j] == zero element
            if (randArr[j] == 0)
                swap(randArr, j, i);
        }

        // make DIS matrix
        for (int j = 0; j < n; j++)
            disArr[i * n + j] = randArr[j];
    }

    return disArr;
}