#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/chromosomeMP.h"

void queensMain() {
    int n, *queensMatrix = NULL, *e = NULL;

    n = getQueensInitValues();

    if (n < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    chromosomeMP(n, &makePerm);

    // make initial population
    queensMatrix = setQueensSol(n);

    // evaluating made population
    e = evalQueens(queensMatrix, n);

    printMatrix(n, queensMatrix);
    printArray(n, e, "Evaluation (Collisions are counted): ");
}