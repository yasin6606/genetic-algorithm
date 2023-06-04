#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/sharedMenu.h"
#include "../../headers/crossover.h"

void queensMain() {
    int queensNum, *queensMatrix = NULL, *evaluatedArr = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL,
            crossoverType;

    // Get initial values
    queensNum = intInput("Enter the number of queens: ");
    crossoverType = crossoverMenu();

    if (queensNum < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // make initial population
    queensMatrix = setQueensSol(queensNum);

    // evaluating made population
    evaluatedArr = evalQueens(queensMatrix, queensNum);

    // The best parent selection
    bestParentsIdx = parentSelection(evaluatedArr, queensNum, false);

    // Re-allocate memory to children based on population size
    firstChild = reallocarray(firstChild, queensNum, sizeof(int));
    secondChild = reallocarray(secondChild, queensNum, sizeof(int));

    if (crossoverType == 1) {
        // Crossover based on two breaking points
        crossover2P(
                &queensMatrix[bestParentsIdx[0] * queensNum],
                &queensMatrix[bestParentsIdx[1] * queensNum],
                queensNum,
                false,
                firstChild,
                secondChild
        );
    } else {
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

    printArray(queensNum, evaluatedArr, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
}