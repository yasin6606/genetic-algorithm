#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"
#include "../headers/makers.h"

int selectionHandler(int *evaluationArr, bool type, int *randIdxArr) {
    int temp, bestParent = evaluationArr[randIdxArr[0]], bestParentIdx = randIdxArr[0];

    /*
     * type: Select the best parent (the best chromosome), based on type (minimum or maximum).
     * true: select maximum
     * false: select minimum
     */
    for (int i = 0; i < K_COMPETITION; i++) {

        // Select a parent (chromosome)
        temp = evaluationArr[randIdxArr[i]];

        if (type && bestParent < temp) {
            bestParent = temp;
            bestParentIdx = randIdxArr[i];
        }

        if (!type && bestParent > temp) {
            bestParent = temp;
            bestParentIdx = randIdxArr[i];
        }
    }

    return bestParentIdx;
}

// Find the best parent's indexes based on (Random K Competition Algorithm).
void *parentSelection(void *evaluationArr, size_t populationNum, bool type) {
    int *parentIdx = (int *) calloc(PARENTS_NUM, sizeof(int)), *randIdxArr, tempArr[K_COMPETITION];

    // Generate (PARENTS_NUM * K_COMPETITION) random indexes so as to select PARENTS_NUM parents on K Competition mode.
    randIdxArr = chromosomeMaker(populationNum, false, true, PARENTS_NUM * K_COMPETITION, 0);

    for (int i = 0; i < PARENTS_NUM; i++) {
        for (int j = 0; j < K_COMPETITION; j++)
            tempArr[j] = randIdxArr[(i * K_COMPETITION) + j];

        // Save the row number of each parent.
        parentIdx[i] = selectionHandler(evaluationArr, type, tempArr);
    }

    free(randIdxArr);

    return parentIdx;
}