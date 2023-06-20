#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../types/GeneralTypes.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/printing.h"
#include "../../plot/plot.h"

void queensMain() {
    int chromosomeLen, populationLen, iteration, eliteNum, *population = NULL, *evaluatedArr = NULL, crossoverType, *evalSortedIdx = NULL,
            *newPop = NULL, plotLen, *bestSolves = NULL;

    SharedMenuType inputs;

    // Get initial values
    inputs = sharedInitInputs();

    chromosomeLen = inputs.chromosomeLen;

    if (chromosomeLen < 4) {
        SHOW_WARNING("Minimum queens must be 4 or upper!");
        return;
    }

    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    // Set default value for plot X axios
    plotLen = iteration;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Elites
    eliteNum = ceil(populationLen * ELITE_PERCENT);

    // Produce init population
    population = setQueensSol(populationLen, chromosomeLen);

    for (int i = 0; i < iteration; i++) {

        // Evaluation
        evaluatedArr = evalQueens(population, populationLen, chromosomeLen);

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evaluatedArr, populationLen);

        // Add each loop's best solve result to best array
        bestSolves[i] = evaluatedArr[evalSortedIdx[0]];

        // Stop Condition if zero collision found
        if (bestSolves[i] == 0) {
            plotLen = i;

            // Print answer
            printArray(chromosomeLen, &population[evalSortedIdx[0] * chromosomeLen], "Answer: ", ANSI_COLOR_MAGENTA);

            break;
        }

        // Crossover (Re-Produce a new generation (population))
        newPop = crossover(
                populationLen,
                chromosomeLen,
                population,
                eliteNum,
                evalSortedIdx,
                evaluatedArr,
                false,
                false,
                crossoverType
        );

        // Mutation (Tweak)
        tweak(newPop, populationLen, chromosomeLen);

        // Re-Take new population
        population = newPop;
    }

    // Plot
    plotPY(bestSolves, plotLen + 1, "-", "b", "N-Queens Problem", "Collision", "Iteration");
}