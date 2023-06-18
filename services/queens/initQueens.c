#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

int *setQueensSol(size_t populationLen, size_t chromosomeLen) {
    int *queensArr = (int *) calloc(populationLen * chromosomeLen, sizeof(int)), *permArr = NULL, i = -1, j = 0;

    do {
        // Rows
        if (i == -1 || j == chromosomeLen) {
            permArr = makePerm(chromosomeLen, false, -1, 0);

            j = 0;
            i++;
        }

        // Add each chromosome to population array
        queensArr[(i * chromosomeLen) + j] = permArr[j];
        j++;
    } while (i < populationLen);

    return queensArr;
}