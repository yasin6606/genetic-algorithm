#include "../../services/tsp/initTSP.c"

void tspMain() {
    int citiesSize, *disMatrix;

    citiesSize = getTSPInitValues();

    disMatrix = setDisSol(citiesSize);

    printMatrix(citiesSize, disMatrix);
}