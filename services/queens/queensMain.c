#include "./initQueens.c"
#include "./evalQueens.c"

void queensMain() {
    int n, *queensMatrix = NULL, *e = NULL;

    n = getQueensInitValues();

    if (n < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // make initial population
    queensMatrix = setQueensSol(n);

    // evaluating made population
    e = evalQueens(queensMatrix, n);

    printMatrix(n, queensMatrix);
    printArray(n, e, "Evaluation (Collisions are counted): ");
}