#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"

void tspMain() {
    int citiesSize, *disMatrix, *evalDisMatrix;

    citiesSize = getTSPInitValues();

    disMatrix = setDisSol(citiesSize);

    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    printMatrix(citiesSize, disMatrix);

    printArray(citiesSize, evalDisMatrix, "Evaluation: ");
}