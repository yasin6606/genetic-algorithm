#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMenu.h"

void knapsackMain() {
    struct KnapsackInitValues init;
    int productsNum, wMax, *matrixResult = NULL, *evalResults = NULL;

    productsNum = intInput("Enter the number of products: ");
    wMax = intInput("Enter the maximum weight of knapsack: ");
    init = getKnapsackStructInfo(productsNum, wMax);

    // Produce population by multi processes for Knapsack
    matrixResult = multiprocessor(productsNum, productsNum * productsNum, &knapsackPopulationMaker, 0);

    evalResults = evalKnapsack(matrixResult, init);

    printArray(productsNum, init.wArr, "Weight: ", ANSI_COLOR_RESET);
    printArray(productsNum, init.vArr, "Value: ", ANSI_COLOR_RESET);

    printMatrix(productsNum, matrixResult, true);

    printArray(productsNum, evalResults, "Evaluation (Values): ", ANSI_COLOR_RESET);
}