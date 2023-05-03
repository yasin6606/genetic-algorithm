#include "./initKnapsack.c"
#include "./evalKnapsack.c"

void knapsackMain() {
    struct KnapsackInitValues init;
    int *matrixResult, *evalResults;

    init = getKnapsackInitValues();

    matrixResult = setKnapsackSol(init);

    evalResults = eval(matrixResult, init);

    printArray(init.n, init.wArr, "Weight: ");
    printArray(init.n, init.vArr, "Value: ");

    printMatrix(init.n, matrixResult);

    printArray(init.n, evalResults, "Evaluation: ");
}