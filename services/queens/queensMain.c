#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"

void queensMain() {
    int n, *queensMatrix = NULL, *evaluatedArr = NULL;

    n = getQueensInitValues();

    if (n < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // make initial population
    queensMatrix = setQueensSol(n);

    printMatrix(n, queensMatrix);

    // evaluating made population
    evaluatedArr = evalQueens(queensMatrix, n);

    // The best parent selection
    parentSelection(evaluatedArr, n, false);

    printArray(n, evaluatedArr, "Evaluation (Collisions are counted): ");
}