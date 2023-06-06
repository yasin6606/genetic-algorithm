#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"

void queensMain() {
    int queensNum, *queensMatrix = NULL, *evalResult = NULL;

    // Get the number of queens
    queensNum = intInput("Enter the number of Queens: ");

    if (queensNum < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // Produce population by multi processes for N-Queens
    queensMatrix = multiprocessor(queensNum, queensNum * queensNum, &queensPopulationMaker, 0);

    // evaluating made population
    evalResult = multiprocessor(queensNum, queensNum, &evalQueens, 1, queensMatrix);

    printMatrix(queensNum, queensMatrix, true);

    printArray(queensNum, evalResult, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
}