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

    // Produce population by multi processes for N-Queens
    queensMatrix = chromosomeMP(n, &queensPopulationMaker);

    // evaluating made population
    e = evalQueens(queensMatrix, n);

    printMatrix(n, queensMatrix);

    printArray(n, e, "Evaluation (Collisions are counted): ");
}