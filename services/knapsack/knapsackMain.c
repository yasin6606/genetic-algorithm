#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/sharedMenu.h"
#include "../../headers/crossover.h"

void knapsackMain() {
    struct KnapsackInitValues knapsackStruct;
    int productsNum, wMax, *matrixResult = NULL, *evalResults = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL,
            crossoverType;

    // Get initial values
    productsNum = intInput("Enter the number of products: ");
    wMax = intInput("Enter the maximum weight of backpack (KG): ");
    knapsackStruct = getKnapsackStructInfo(productsNum, wMax);
    crossoverType = crossoverMenu();

    // Produce population
    matrixResult = setKnapsackSol(productsNum);

    // Evaluate population produced
    evalResults = evalKnapsack(matrixResult, knapsackStruct);

    // Print valid Weights and Values array
    printArray(productsNum, knapsackStruct.wArr, "Weight: ", ANSI_COLOR_YELLOW);
    printArray(productsNum, knapsackStruct.vArr, "Value: ", ANSI_COLOR_YELLOW);

    // The best parent selection
    bestParentsIdx = parentSelection(evalResults, productsNum, true);

    // Re-allocate memory to children based on population size
    firstChild = (int *) reallocarray(firstChild, productsNum, sizeof(int));
    secondChild = (int *) reallocarray(secondChild, productsNum, sizeof(int));

    if (crossoverType == 1) {
        // Crossover based on two breaking point algorithm
        crossover2P(
                &matrixResult[bestParentsIdx[0] * productsNum],
                &matrixResult[bestParentsIdx[1] * productsNum],
                productsNum,
                true,
                firstChild,
                secondChild
        );
    } else {
        // Crossover based on uniform algorithm
        crossoverUni(
                &matrixResult[bestParentsIdx[0] * productsNum],
                &matrixResult[bestParentsIdx[1] * productsNum],
                productsNum,
                true,
                firstChild,
                secondChild
        );
    }

    printArray(productsNum, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(productsNum, secondChild, "Second Child: ", ANSI_COLOR_RESET);

    printMatrix(productsNum, matrixResult, true);

    printArray(productsNum, evalResults, "Evaluation (Values): ", ANSI_COLOR_RESET);
}