#include "../headers/sharedLib.h"
#include "../headers/makers.h"

void crossover2P(int *firstParent, int *secondParent, size_t populationNum, bool ignorePerm, int *firstChild,
                 int *secondChild) {
    int *breakPoints = NULL, *temp = NULL;

    // Get break points
    breakPoints = breakPointGenerator(populationNum);

    // Generate first child (chromosome)
    temp = childGenerator(populationNum, breakPoints, ignorePerm, firstParent, secondParent);
    for (int i = 0; i < populationNum; i++)
        firstChild[i] = temp[i];

    // Generate second child (chromosome)
    temp = childGenerator(populationNum, breakPoints, ignorePerm, secondParent, firstParent);
    for (int i = 0; i < populationNum; i++)
        secondChild[i] = temp[i];
}