#include "../headers/sharedLib.h"

int *childGenerator(size_t populationNum, int *breakPoints, int *oneParent, int *anotherParent) {
    int i, *child = (int *) calloc(populationNum, sizeof(int));

    // Fill first child's part
    for (i = 0; i < breakPoints[0]; i++)
        child[i] = oneParent[i];

    // Fill second child's part
    for (i = breakPoints[1]; i < populationNum; i++)
        child[i] = oneParent[i];

    // Fill third child's part
    for (i = breakPoints[0]; i < breakPoints[1]; i++)
        child[i] = anotherParent[i];

    return child;
}