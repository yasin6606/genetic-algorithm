#include "../headers/sharedLib.h"

int *childGenerator2P(size_t populationNum, int *breakPoints, bool ignorePerm, int *oneParent, int *anotherParent) {
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
            // Save empty gens indexes so as to fill them in next section.
            permEmptyIdx[k] = i;
            k++;
        }
    }

    // Make generated child (child chromosome) permutation. (! Based on middle part)
    if (!ignorePerm)
        for (i = breakFirst; i < breakLast; i++) {
            temp = oneParent[i];

            if (flag[temp] == 1) continue;

            // Fill empty gens based on being permutation.
            child[permEmptyIdx[j]] = temp;
            flag[temp] = 1;

            j++;
        }

    return child;
}

int *childGeneratorUni(size_t populationNum, bool ignorePerm, int *mask, int *oneParent, int *anotherParent) {
    int i, k = 0, temp,
            *child = (int *) calloc(populationNum, sizeof(int)),
            *flag = (int *) calloc(populationNum, sizeof(int)),
            *permEmptyIdx = (int *) calloc(populationNum, sizeof(int));

    for (i = 0; i < populationNum; i++) {

        // Select from first parent. ! Without consider ignorePerm.
        if (mask[i] == 0) {
            temp = oneParent[i];
            child[i] = temp;

            if (!ignorePerm)
                flag[temp] = 1;

            continue;
        }

        // Select from second parent. Just when permutation is ignored.
        if (ignorePerm && mask[i] == 1)
            child[i] = anotherParent[i];
    }

    // Make current child permutation if ignoredPerm is false.
    if (!ignorePerm) {

        // Select from another parent.
        for (i = 0; i < populationNum; i++) {
            if (mask[i] == 0) continue;

            temp = anotherParent[i];

            // Save empty index
            if (flag[temp] == 1) {
                permEmptyIdx[k] = i;
                k++;

                continue;
            }

            child[i] = temp;
            flag[temp] = 1;
        }

        // To reuse of k in order to read from permEmptyIdx, re-initialize it to 0.
        k = 0;

        // Fill empty indexes based permutation.
        for (i = 0; i < populationNum; i++) {
            temp = oneParent[i];

            if (mask[i] == 0 || flag[temp] == 1) continue;

            child[permEmptyIdx[k]] = temp;
            k++;

            flag[temp] = 1;
        }
    }

    return child;
}