#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/crossover.h"

void queensMain() {
    int queensNum, crossoverType, *queensMatrix = NULL, *evalResult = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL;

    // Get the number of queens
    queensNum = intInput("Enter the number of Queens: ");
    crossoverType = crossoverMenu();

    if (queensNum < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // Produce population by multi processes for N-Queens
    queensMatrix = multiprocessor(queensNum, queensNum * queensNum, &queensPopulationMaker, 0);

    // evaluating made population
    evalResult = multiprocessor(queensNum, queensNum, &evalQueens, 1, queensMatrix);

    // Selection parents based on K-Competition algorithm
    bestParentsIdx = parentSelection(evalResult, queensNum, true);

    firstChild = (int *) calloc(queensNum, sizeof(int));
    secondChild = (int *) calloc(queensNum, sizeof(int));

    // Crossover
    if (crossoverType == 1) { // Two breaking points
        crossover2P(
                &queensMatrix[bestParentsIdx[0] * queensNum],
                &queensMatrix[bestParentsIdx[1] * queensNum],
                queensNum,
                false,
                firstChild,
                secondChild
        );
    } else { // Uniform
        crossoverUni(
                &queensMatrix[bestParentsIdx[0] * queensNum],
                &queensMatrix[bestParentsIdx[1] * queensNum],
                queensNum,
                false,
                firstChild,
                secondChild
        );
    }

    printArray(queensNum, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(queensNum, secondChild, "Second Child: ", ANSI_COLOR_RESET);

    printMatrix(queensNum, queensMatrix, true);

    printArray(queensNum, evalResult, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
}