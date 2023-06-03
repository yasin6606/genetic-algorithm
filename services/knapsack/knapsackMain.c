#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/crossover.h"

void knapsackMain() {
    struct KnapsackInitValues init;
    int *matrixResult = NULL, *evalResults = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL;

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
    bestParentsIdx = parentSelection(evalResults, init.n, true);

    // Re-allocate memory to children based on population size
    firstChild = (int *) reallocarray(firstChild, init.n, sizeof(int));
    secondChild = (int *) reallocarray(secondChild, init.n, sizeof(int));

    // Crossover based on two breaking points
    crossover2P(
            &matrixResult[bestParentsIdx[0] * init.n],
            &matrixResult[bestParentsIdx[1] * init.n],
            init.n,
            true,
            firstChild,
            secondChild
    );

    printArray(init.n, firstChild, "First Child: ");
    printArray(init.n, secondChild, "Second Child: ");

    printMatrix(init.n, matrixResult);

    printArray(init.n, evalResults, "Evaluation (Values): ");
}