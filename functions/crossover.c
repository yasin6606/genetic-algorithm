#include "../headers/sharedLib.h"
#include "../headers/makers.h"

/*
 * crossover2P generates two new different chromosomes based on two breaking points which the first point always should be smaller
 * that the second one and the difference between points must be greater than 1. Moreover, this function give an argument that is called
 * ignorePerm which define new chromosomes should be permutation or not.
 * */
void crossover2P(int *firstParent, int *secondParent, size_t populationNum, bool ignorePerm, int *firstChild,
                 int *secondChild) {
    int *breakPoints = NULL, *temp = NULL;

    // Get break points
    breakPoints = breakPointGenerator(populationNum);

    printArray(PARENTS_NUM, breakPoints, "Breaking points: ", ANSI_COLOR_RED);

    // Generate first child (chromosome)
    temp = childGenerator2P(populationNum, breakPoints, ignorePerm, firstParent, secondParent);
    for (int i = 0; i < populationNum; i++)
        firstChild[i] = temp[i];

    // Generate second child (chromosome)
    temp = childGenerator2P(populationNum, breakPoints, ignorePerm, secondParent, firstParent);
    for (int i = 0; i < populationNum; i++)
        secondChild[i] = temp[i];
}

void crossoverUni(int *firstParent, int *secondParent, size_t populationNum, bool ignorePerm, int *firstChild,
                  int *secondChild) {
    int *temp = NULL, *mask = chromosomeMaker(populationNum, true, false, -1, 0);

    printArray(populationNum, mask, "Mask: ", ANSI_COLOR_MAGENTA);

    // Generate first child (chromosome)
    temp = childGeneratorUni(populationNum, ignorePerm, mask, firstParent, secondParent);
    for (int i = 0; i < populationNum; i++)
        firstChild[i] = temp[i];

    // Generate second child (chromosome)
    temp = childGeneratorUni(populationNum, ignorePerm, mask, secondParent, firstParent);
    for (int i = 0; i < populationNum; i++)
        secondChild[i] = temp[i];
}