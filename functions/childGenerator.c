#include "../headers/sharedLib.h"
#include "../headers/printing.h"

int *childGenerator(size_t populationNum, int *breakPoints, bool ignorePerm, int *oneParent, int *anotherParent) {
    int i, j = 0, k = 0, temp, breakFirst = breakPoints[0], breakLast = breakPoints[1],
            *child = (int *) calloc(populationNum, sizeof(int)),
            *flag = (int *) calloc(populationNum, sizeof(int)),
            *permEmptyIdx = (int *) calloc(breakLast - breakFirst, sizeof(int));

    // Fill first the child's part (first side)
    for (i = 0; i < breakFirst; i++) {
        temp = oneParent[i];
        child[i] = temp;

        if (!ignorePerm)
            flag[temp] = 1;
    }

    // Fill second the child's part (last side)
    for (i = breakLast; i < populationNum; i++) {
        temp = oneParent[i];
        child[i] = temp;

        if (!ignorePerm)
            flag[temp] = 1;
    }

    // Fill third the child's part (middle part)
    for (i = breakFirst; i < breakLast; i++) {
        temp = anotherParent[i];

        if (ignorePerm) {
            child[i] = temp;

            continue;
        }

        if (flag[temp] == 0) {
            child[i] = temp;

            flag[temp] = 1;
            continue;
        } else {
            permEmptyIdx[k] = i;
            k++;
        }
    }

    // Make generated child (child chromosome) permutation. (! Based on middle part)
    if (!ignorePerm)
        for (i = breakFirst; i < breakLast; i++) {
            temp = oneParent[i];

            if (flag[temp] == 1) continue;

            child[permEmptyIdx[j]] = temp;
            flag[temp] = 1;

            j++;
        }

    return child;
}