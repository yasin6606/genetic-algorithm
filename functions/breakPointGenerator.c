#include "../headers/sharedLib.h"
#include "../headers/makers.h"

// Find two break points so as to crossover on selected parents.
int *breakPointGenerator(size_t populationNum) {
    int *breakPoints = NULL;

    while (1) {
        breakPoints = chromosomeMaker(populationNum, false, true, 2, 2, 0, populationNum - 1);

        if (abs(breakPoints[0] - breakPoints[1]) > 1) break;

        free(breakPoints);
    }

    // Swap break points if first point is greater that second one.
    if (breakPoints[0] > breakPoints[1])
        swap(breakPoints, 0, 1);

    return breakPoints;
}