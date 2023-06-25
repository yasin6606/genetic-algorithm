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
    for (int i = 1; i < K_COMPETITION; i++) {

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
    int *parentIdx = (int *) calloc(PARENTS_NUM, sizeof(int)), *randIdxArr = NULL;

    for (int i = 0; i < PARENTS_NUM; i++) {
        randIdxArr = chromosomeMaker(populationNum, false, true, K_COMPETITION, i, parentIdx[i - 1]);

        // Save the row number of each parent.
        parentIdx[i] = selectionHandler(evaluationArr, type, randIdxArr);

        free(randIdxArr);
    }

    return parentIdx;
}