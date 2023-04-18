#include "../../services/tsp/initTSP.c"

void tspMain() {
    int citiesSize = 0;

    citiesSize = getTSPInitValues();

    setDisSol(citiesSize);
}