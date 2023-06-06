#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"

void queensMain() {
    int queensNum, *queensMatrix = NULL, *e = NULL;

    // Get the number of queens
    queensNum = intInput("Enter the number of Queens: ");

    if (queensNum < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // Produce population by multi processes for N-Queens
    queensMatrix = multiprocessor(queensNum, queensNum * queensNum, &queensPopulationMaker, 0);

    // evaluating made population
    e = evalQueens(queensMatrix, queensNum);

    printMatrix(queensNum, queensMatrix, true);

    printArray(queensNum, e, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
}