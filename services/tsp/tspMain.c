#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/printing.h"

void tspMain() {
    int citiesSize, *disMatrix = NULL, *evalDisMatrix = NULL;

    // Get initial values
    citiesSize = getTSPInitValues();

    // Produce population
    disMatrix = setDisSol(citiesSize);

    // Evaluate population produced
    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    // The best parent selection
    parentSelection(evalDisMatrix, citiesSize, false);

    printMatrix(citiesSize, disMatrix);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ");
}