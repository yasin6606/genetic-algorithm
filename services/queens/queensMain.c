#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../types/GeneralTypes.h"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMacros.h"
#include "../../plot/plot.h"

void queensMain() {
    int chromosomeLen, populationLen, iteration, crossoverType, eliteNum, *population = NULL, *evalResult = NULL, *evalSortedIdx = NULL,
            *newPop = NULL, plotLen, *bestSolves = NULL;

    SharedMenuType inputs;

    // Get the number of queens
    inputs = sharedInitInputs();
    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    if (chromosomeLen < 4) {
        SHOW_WARNING("Minimum queens must be 4 or upper");

        return;
    }

    // Set default value for plot X axios
    plotLen = iteration;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Get the number of chromosomes which must move to new population directly
    eliteNum = ceil(populationLen * ELITE_PERCENT);

    // Produce init population by multi processes for N-Queens
    population = (int *) multiprocessor(
            populationLen,
            chromosomeLen,
            populationLen * chromosomeLen,
            &queensPopulationMaker,
            0
    );

    for (int i = 0; i < iteration; i++) {

        // Evaluation
        evalResult = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                populationLen,
                &evalQueens,
                1,
                population
        );

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        // Add each loop's best solve result to best array
        bestSolves[i] = evalResult[evalSortedIdx[0]];

        // Stop Condition if zero collision found
        if (bestSolves[i] == 0) {
            plotLen = i;

            // Print answer
            printArray(chromosomeLen, &population[evalSortedIdx[0] * chromosomeLen], "Answer: ", ANSI_COLOR_MAGENTA);

            break;
        }

        // Crossover
        newPop = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                populationLen * chromosomeLen,
                &crossover,
                7,
                population,
                evalResult,
                evalSortedIdx,
                false,
                false,
                crossoverType,
                eliteNum
        );

        // Tweak (Mutation)
        tweak(newPop, chromosomeLen, populationLen);

        // Re-Take the new population
        population = newPop;
    }

//    printCustomMatrix(populationLen, chromosomeLen, population, false);
//    printArray(populationLen, evalResult, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
//    printArray(populationLen, evalSortedIdx, "Evaluation Sorted Indexes (Collisions are counted): ", ANSI_COLOR_RESET);

    plotPY(bestSolves, plotLen + 1, "-", "b", "N-Queens Problem", "Collision", "Iteration");
}