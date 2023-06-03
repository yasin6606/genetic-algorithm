#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/crossover.h"
#include "../../headers/printing.h"

void tspMain() {
    int citiesSize, *disMatrix = NULL, *evalDisMatrix = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL;

    // Get initial values
    citiesSize = getTSPInitValues();

    // Produce population
    disMatrix = setDisSol(citiesSize);

    // Evaluate population produced
    evalDisMatrix = evalTSP(disMatrix, citiesSize);

    // The best parents selection so as to crossover
    bestParentsIdx = parentSelection(evalDisMatrix, citiesSize, false);

    // Re-allocate memory to children based on population size
    firstChild = (int *) reallocarray(firstChild, citiesSize, sizeof(int));
    secondChild = (int *) reallocarray(secondChild, citiesSize, sizeof(int));

    // Crossover based on two breaking points
    crossover2P(
            &disMatrix[bestParentsIdx[0] * citiesSize],
            &disMatrix[bestParentsIdx[1] * citiesSize],
            citiesSize,
            false,
            firstChild,
            secondChild
    );

    printArray(citiesSize, firstChild, "First Child: ");
    printArray(citiesSize, secondChild, "Second Child: ");

    printMatrix(citiesSize, disMatrix);

    printArray(citiesSize, evalDisMatrix, "Evaluation (Distances): ");
}