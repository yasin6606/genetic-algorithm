#include "../includes/sharedLib.h"
#include "../includes/sharedMacros.h"
#include "../includes/makers.h"
#include "../includes/assets.h"

// Find two break points so as to crossover on selected parents.
int *breakPointGenerator(size_t populationNum) {
    int *breakPoints = NULL, ignoreArr[TWO_LEN] = {0, populationNum - 1};

    while (1) {
        breakPoints = chromosomeMaker(populationNum, false, true, TWO_LEN, TWO_LEN, ignoreArr);

        if (abs(breakPoints[0] - breakPoints[1]) > 1) break;

        free(breakPoints);
    }

    // Swap break points if first point is greater that second one.
    if (breakPoints[0] > breakPoints[1])
        swap(breakPoints, 0, 1);

    return breakPoints;
}