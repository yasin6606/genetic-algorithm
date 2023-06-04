#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

int *setQueensSol(size_t nQueens) {
    int *queensArr = (int *) calloc(nQueens * nQueens, sizeof(int)),
            *permArr = makePerm(nQueens, false, -1, 0), i = 0, j = 0;

    while (i < nQueens) {
        if (j == nQueens) {

            // ! ! ! Per each row creation, start making new permutation array ! ! !
            permArr = makePerm(nQueens, false, -1, 0);

            i++;
            j = 0;
        }

        // add each element to each sol
        queensArr[i * nQueens + j] = permArr[j];

        j++;
    }

    return queensArr;
}