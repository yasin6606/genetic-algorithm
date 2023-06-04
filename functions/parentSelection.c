#include "../headers/sharedLib.h"
#include "../headers/assistant.h"
#include "../headers/sharedMacros.h"
#include "../headers/makers.h"
#include "../headers/printing.h"

int selectionHandler(int *evaluationArr, bool type, int *randIdxArr) {
    int temp, bestParent = evaluationArr[randIdxArr[0]], bestParentIdx = randIdxArr[0];

    /*
     * type: Select the best parent (the best chromosome), based on type (minimum or maximum).
     * true: select maximum
     * false: select minimum
     */
    for (int i = 0; i < K; i++) {

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
    int *parentIdx = (int *) calloc(PARENTS_NUM, sizeof(int)), *randIdxArr, tempArr[K];
    randIdxArr = makePerm(populationNum, false, -1, 0);

    for (int i = 0; i < PARENTS_NUM; i++) {
        for (int j = 0; j < K; j++)
            tempArr[j] = randIdxArr[(i * K) + j];

        // Save the row number of each parent.
        parentIdx[i] = selectionHandler(evaluationArr, type, tempArr);
    }

    printArray(PARENTS_NUM, parentIdx, "Best Parents: ", ANSI_COLOR_CYAN);

    return parentIdx;
}