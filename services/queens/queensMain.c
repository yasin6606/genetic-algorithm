#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMacros.h"
#include "../../plot/plot.h"

void queensMain() {
    int queensNum, populationLen, stop, crossoverType, elitePercent, *population = NULL, *evalResult = NULL, *evalSortedIdx = NULL,
            *newPop = NULL;

    int f = 0, r = -1, c = -1;

    // Get the number of queens
    queensNum = intInput("Enter the number of Queens (Each chromosome's gens): ");
    populationLen = intInput("Enter the length of population: ");
    stop = intInput("Enter the number of loops: ");
    crossoverType = crossoverMenu();

    // Get the number of chromosomes which must move to new population directly
    elitePercent = ceil(populationLen * ELITE_PERCENT);

    if (queensNum < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // Produce population by multi processes for N-Queens
    population = multiprocessor(
            populationLen,
            queensNum,
            populationLen * queensNum,
            &queensPopulationMaker,
            0
    );

    // Init evaluation
    evalResult = (int *) multiprocessor(populationLen, queensNum, queensNum, &evalQueens, 1, population);

    // Init sorting evaluation
    evalSortedIdx = sortChromosomes(evalResult, populationLen);

    for (int i = 0; i < stop; i++) {

//        DASHED_LINE
//        printf("i: %d\n", i);
//        printCustomMatrix(populationLen, queensNum, population, true);
//        printArray(elitePercent, evalSortedIdx, "S: ", ANSI_COLOR_RESET);
//        for (int j = 0; j < elitePercent; j++) {
//            printArray(queensNum, &population[evalSortedIdx[j] * queensNum], "", ANSI_COLOR_RESET);
//        }

        if (evalResult[evalSortedIdx[0]] == 0) break;

        // Crossover
        newPop = (int *) multiprocessor(
                populationLen,
                queensNum,
                populationLen * queensNum,
                &crossover,
                6,
                population,
                evalResult,
                evalSortedIdx,
                false,
                crossoverType,
                elitePercent
        );

        // Tweak (Mutation)
        tweak(newPop, queensNum, populationLen);

        // evaluating made population
        evalResult = (int *) multiprocessor(populationLen, queensNum, queensNum, &evalQueens, 1, population);

        // Sort evaluation result in order to direct send 4% of the best chromosomes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        population = newPop;
    }

//    printCustomMatrix(populationLen, queensNum, population, false);
    printArray(populationLen, evalResult, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
//    printArray(populationLen, evalSortedIdx, "Evaluation Sorted Indexes (Collisions are counted): ", ANSI_COLOR_RESET);

    plotPY(evalResult, populationLen);
}