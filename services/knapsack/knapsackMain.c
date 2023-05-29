#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/chromosomeMP.h"

void knapsackMain() {
    struct KnapsackInitValues init;
    int *matrixResult = NULL, *evalResults = NULL;

    init = getKnapsackInitValues();

    chromosomeMP(init.n, makeBin);

    matrixResult = setKnapsackSol(init);

    evalResults = evalKnapsack(matrixResult, init);

    printArray(init.n, init.wArr, "Weight: ");
    printArray(init.n, init.vArr, "Value: ");

    printMatrix(init.n, matrixResult);

    printArray(init.n, evalResults, "Evaluation (Values): ");
}