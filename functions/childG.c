#include "../headers/sharedLib.h"
#include "../headers/makers.h"

int *childG(size_t populationNum, int *breakPoints, int *p1, int *p2) {
    int *producedChild = (int *) calloc(populationNum, sizeof(int)), b1 = breakPoints[0], b2 = breakPoints[1],
            *flag = (int *) calloc(populationNum, sizeof(int)), *permIdx = (int *) calloc(populationNum, sizeof(int)),
            temp, k = 0;

    // Middle side
    for (int i = b1; i < b2; i++) {
        temp = p1[i];
        producedChild[i] = temp;
        flag[temp] = 1;
    }

    // left side
    for (int i = 0; i < b1; i++) {
        temp = p2[i];

        if (flag[temp] == 1) {
            permIdx[k] = i;
            k++;

            continue;
        }

        producedChild[i] = temp;
        flag[temp] = 1;
    }

    // right side
    for (int i = b2; i < populationNum; i++) {
        temp = p2[i];

        if (flag[temp] == 1) {
            permIdx[k] = i;
            k++;

            continue;
        }

        producedChild[i] = temp;
        flag[temp] = 1;
    }

    k = 0;

    for (int i = b1; i < b2; i++) {
        temp = p2[i];

        if (flag[temp] == 1) continue;

        producedChild[permIdx[k]] = temp;
        k++;

        flag[temp] = 1;
    }

    return producedChild;
}