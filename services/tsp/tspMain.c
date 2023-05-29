#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/chromosomeMP.h"
#include "diameterZeroMaker.c"

void tspMain() {
    int citiesSize, *disMatrix = NULL, *evalDisMatrix = NULL;

    // Get the number of cities
    citiesSize = getTSPInitValues();

    // Produce population by multi processes
    disMatrix = chromosomeMP(citiesSize, &makePerm);

    // Make elements on main diameter zero
    diameterZeroMaker(disMatrix, citiesSize);

    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    printMatrix(citiesSize, disMatrix);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ");
}