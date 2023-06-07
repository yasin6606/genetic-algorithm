#include "./initTSP.c"
#include "./evalTSP.c"
#include "../../headers/sharedMenu.h"
#include "../../headers/crossover.h"

void tspMain() {
    int citiesSize, *population = NULL, *disMatrix = NULL, *evalDisMatrix = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL,
            crossoverType;

    // Get initial values
    citiesSize = intInput("Enter the number of cities: ");
    crossoverType = crossoverMenu();

    // Produce population
    population = tspPopulationMaker(citiesSize);

    // Produce DIS matrix
    disMatrix = tspDisMaker(citiesSize);

    // Evaluate population produced
    evalDisMatrix = evalTSPPopulation(citiesSize, disMatrix, population);

    // The best parents selection so as to crossover
    bestParentsIdx = parentSelection(evalDisMatrix, citiesSize, false);

    // Re-allocate memory to children based on population size
    firstChild = (int *) reallocarray(firstChild, citiesSize, sizeof(int));
    secondChild = (int *) reallocarray(secondChild, citiesSize, sizeof(int));

    if (crossoverType == 1) {
        // Crossover based on two breaking point algorithm
        crossover2P(
                &disMatrix[bestParentsIdx[0] * citiesSize],
                &disMatrix[bestParentsIdx[1] * citiesSize],
                citiesSize,
                false,
                firstChild,
                secondChild
        );
    } else {
        // Crossover based on uniform algorithm
        crossoverUni(
                &disMatrix[bestParentsIdx[0] * citiesSize],
                &disMatrix[bestParentsIdx[1] * citiesSize],
                citiesSize,
                false,
                firstChild,
                secondChild
        );
    }

    printArray(citiesSize, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(citiesSize, secondChild, "Second  Child: ", ANSI_COLOR_RESET);

    printMatrix(citiesSize, disMatrix, true);
    printMatrix(citiesSize, population, true);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ", ANSI_COLOR_RESET);
}