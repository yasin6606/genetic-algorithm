#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/crossover.h"

void knapsackMain() {
    int productsNum, wMax, crossoverType, *wArr, *vArr, *population = NULL, *evalResults = NULL, *bestParentsIdx,
            *firstChild, *secondChild;

    // Get initial values
    productsNum = intInput("Enter the number of products: ");
    wMax = intInput("Enter the maximum weight of knapsack: ");
    crossoverType = crossoverMenu();

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

    // Selection parents based on K-Competition algorithm
    bestParentsIdx = parentSelection(evalResults, productsNum, true);

    firstChild = (int *) calloc(productsNum, sizeof(int));
    secondChild = (int *) calloc(productsNum, sizeof(int));

    // Crossover
    if (crossoverType == 1) { // Two breaking points
        crossover2P(
                &population[bestParentsIdx[0] * productsNum],
                &population[bestParentsIdx[1] * productsNum],
                productsNum,
                true,
                firstChild,
                secondChild
        );
    } else { // Uniform
        crossoverUni(
                &population[bestParentsIdx[0] * productsNum],
                &population[bestParentsIdx[1] * productsNum],
                productsNum,
                true,
                firstChild,
                secondChild
        );
    }

    printArray(productsNum, wArr, "Weight: ", ANSI_COLOR_MAGENTA);
    printArray(productsNum, vArr, "Value: ", ANSI_COLOR_MAGENTA);

    printArray(productsNum, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(productsNum, secondChild, "Second Child: ", ANSI_COLOR_RESET);

    printMatrix(productsNum, population, true);

    printArray(productsNum, evalResults, "Evaluation (Values): ", ANSI_COLOR_RESET);
}