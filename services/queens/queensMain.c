#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMacros.h"

void queensMain() {
    int queensNum, crossoverType, elitePercent, *queensMatrix = NULL, *evalResult = NULL, *evalSortedIdx = NULL;

    // Get the number of queens
    queensNum = intInput("Enter the number of Queens: ");
    crossoverType = crossoverMenu();

    // Get the number of chromosomes which must move to new population directly
    elitePercent = ceil(queensNum * ELITE_PERCENT);

    if (queensNum < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // Produce population by multi processes for N-Queens
    queensMatrix = multiprocessor(queensNum, queensNum * queensNum, &queensPopulationMaker, 0);

    // evaluating made population
    evalResult = multiprocessor(queensNum, queensNum, &evalQueens, 1, queensMatrix);

    // Sort evaluation result in order to direct send 4% of the best chromosomes
    evalSortedIdx = sortChromosomes(evalResult, queensNum);

    // Crossover
    queensMatrix = multiprocessor(
            queensNum,
            queensNum * queensNum,
            &crossover,
            6,
            queensMatrix,
            evalResult,
            evalSortedIdx,
            false,
            crossoverType,
            elitePercent
    );

    printArray(queensNum, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(queensNum, secondChild, "Second Child: ", ANSI_COLOR_RESET);

    printMatrix(queensNum, queensMatrix, true);

    printArray(queensNum, evalResult, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
    printArray(queensNum, evalSortedIdx, "Evaluation Sorted Indexes (Collisions are counted): ", ANSI_COLOR_RESET);
}