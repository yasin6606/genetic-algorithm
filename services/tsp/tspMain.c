#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/crossover.h"

void tspMain() {
    int citiesSize, crossoverType, *disMatrix = NULL, *evalDisMatrix = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL;

    // Get the number of cities
    citiesSize = intInput("Enter the number of Cities: ");
    crossoverType = crossoverMenu();

    // Produce population by multi processes for TSP
    disMatrix = multiprocessor(citiesSize, citiesSize * citiesSize, &tspPopulationMaker, 0);

    // Evaluation
    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    // Selection parents based on K-Competition algorithm
    bestParentsIdx = parentSelection(evalDisMatrix, citiesSize, true);

    firstChild = (int *) calloc(citiesSize, sizeof(int));
    secondChild = (int *) calloc(citiesSize, sizeof(int));

    // Crossover
    if (crossoverType == 1) { // Two breaking points
        crossover2P(
                &disMatrix[bestParentsIdx[0] * citiesSize],
                &disMatrix[bestParentsIdx[1] * citiesSize],
                citiesSize,
                false,
                firstChild,
                secondChild
        );
    } else { // Uniform
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
    printArray(citiesSize, secondChild, "Second Child: ", ANSI_COLOR_RESET);

    printMatrix(citiesSize, disMatrix, true);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ", ANSI_COLOR_RESET);
}