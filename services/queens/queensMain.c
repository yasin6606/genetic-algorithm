#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/crossover.h"

void queensMain() {
    int n, *queensMatrix = NULL, *evaluatedArr = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL;

    n = getQueensInitValues();

    if (n < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // make initial population
    queensMatrix = setQueensSol(n);

    // evaluating made population
    evaluatedArr = evalQueens(queensMatrix, n);

    // The best parent selection
    bestParentsIdx = parentSelection(evaluatedArr, n, false);

    // Re-allocate memory to children based on population size
    firstChild = reallocarray(firstChild, n, sizeof(int));
    secondChild = reallocarray(secondChild, n, sizeof(int));

    // Crossover based on two breaking points
    crossover2P(
            &queensMatrix[bestParentsIdx[0] * n],
            &queensMatrix[bestParentsIdx[1] * n],
            n,
            false,
            firstChild,
            secondChild
    );

    printArray(n, firstChild, "First Child: ");
    printArray(n, secondChild, "Second Child: ");

    printMatrix(n, queensMatrix);

    printArray(n, evaluatedArr, "Evaluation (Collisions are counted): ");
}