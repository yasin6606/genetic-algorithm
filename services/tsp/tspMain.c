#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"

void tspMain() {
    int citiesSize, *disMatrix = NULL, *evalDisMatrix = NULL;

    // Get the number of cities
    citiesSize = intInput("Enter the number of Cities: ");

    // Produce population by multi processes for TSP
    disMatrix = multiprocessor(citiesSize, citiesSize * citiesSize, &tspPopulationMaker, 0);

    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    printMatrix(citiesSize, disMatrix, true);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ", ANSI_COLOR_RESET);
}