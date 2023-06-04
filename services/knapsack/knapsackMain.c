#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/chromosomeMP.h"
#include "../../headers/sharedMacros.h"

void knapsackMain() {
    struct KnapsackInitValues init;
    int *matrixResult = NULL, *evalResults = NULL;

    init = getKnapsackInitValues();

    // Produce population by multi processes for Knapsack
    matrixResult = chromosomeMP(init.n, &knapsackPopulationMaker);

    evalResults = evalKnapsack(matrixResult, init);

    printArray(init.n, init.wArr, "Weight: ", ANSI_COLOR_RESET);
    printArray(init.n, init.vArr, "Value: ", ANSI_COLOR_RESET);

    printMatrix(init.n, matrixResult, true);

    printArray(init.n, evalResults, "Evaluation (Values): ", ANSI_COLOR_RESET);
}