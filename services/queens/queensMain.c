#include "./initQueens.c"
#include "./evalQueens.c"

void queensMain() {
    int n, *queensMatrix = NULL, *e = NULL;

    n = getQueensInitValues();

    if (n < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // start to get duration
    clock_t begin = clock();

    // make initial population
    queensMatrix = setQueensSol(n);

    // evaluating made population
    e = evalQueens(queensMatrix, n);

    // end duration
    clock_t end = clock();

    printArray(n, e, "Evaluation (Collisions are counted): ");

    printf("\n\nDuration: %f seconds\n\n", ((double) (end - begin)) / CLOCKS_PER_SEC);
}