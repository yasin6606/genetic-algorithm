#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/chromosomeMP.h"

void tspMain() {
    int citiesSize, *disMatrix = NULL, *evalDisMatrix = NULL;

    citiesSize = getTSPInitValues();

    chromosomeMP(citiesSize, &makePerm);

    disMatrix = setDisSol(citiesSize);

    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    printMatrix(citiesSize, disMatrix);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ");
}