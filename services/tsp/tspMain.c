#include "./initTSP.c"
#include "./evalTSP.c"
#include "../../headers/sharedMenu.h"
#include "../../headers/printing.h"

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

    printArray(citiesSize, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(citiesSize, secondChild, "Second  Child: ", ANSI_COLOR_RESET);

    printMatrix(citiesSize, disMatrix, true);
    printMatrix(citiesSize, population, true);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ", ANSI_COLOR_RESET);
}