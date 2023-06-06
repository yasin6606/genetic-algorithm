#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMenu.h"

void knapsackMain() {
    int productsNum, wMax, *wArr, *vArr, *population = NULL, *evalResults = NULL;

    productsNum = intInput("Enter the number of products: ");
    wMax = intInput("Enter the maximum weight of knapsack: ");

    // Fill wArr (Weight Array) randomly
    wArr = chromosomeMaker(productsNum, false, false, productsNum, 1, 0);

    // Fill vArr (Value Array) randomly. To be more realistic, divide values.
    vArr = chromosomeMaker(productsNum, false, false, productsNum, 0);

    // Produce population by multi processes for Knapsack
    population = multiprocessor(productsNum, productsNum * productsNum, &knapsackPopulationMaker, 0);

    // Evaluate generated population by multi processes for Knapsack
    evalResults = multiprocessor(
            productsNum,
            productsNum,
            &evalKnapsack,
            4,
            wMax,
            wArr,
            vArr,
            population
    );

    printArray(productsNum, wArr, "Weight: ", ANSI_COLOR_RESET);
    printArray(productsNum, vArr, "Value: ", ANSI_COLOR_RESET);

    printMatrix(productsNum, population, true);

    printArray(productsNum, evalResults, "Evaluation (Values): ", ANSI_COLOR_RESET);
}