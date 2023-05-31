#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"

void knapsackMain() {
    struct KnapsackInitValues init;
    int *matrixResult = NULL, *evalResults = NULL;

    // Get initial values
    init = getKnapsackInitValues();

    // Produce population
    matrixResult = setKnapsackSol(init);

    // Evaluate population produced
    evalResults = evalKnapsack(matrixResult, init);

    // Print valid Weights and Values array
    printArray(init.n, init.wArr, "Weight: ");
    printArray(init.n, init.vArr, "Value: ");

    // The best parent selection
    parentSelection(evalResults, init.n, true);

    printMatrix(init.n, matrixResult);

    printArray(init.n, evalResults, "Evaluation (Values): ");
}