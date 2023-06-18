#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/sharedMenu.h"
#include "../../headers/printing.h"
#include "../../plot/plot.h"

void queensMain() {
    int chromosomeLen, populationLen, stop, eliteNum, *population = NULL, *evaluatedArr = NULL, crossoverType, *evalSortedIdx = NULL,
            *newPop = NULL, plotLen, *bestSolves = NULL;

    // Get initial values
    chromosomeLen = intInput("Enter the length of a chromosome: ");

    if (chromosomeLen < 4) {
        SHOW_WARNING("Minimum queens must be 4 or upper!");
        return;
    }

    populationLen = intInput("Enter the length of population: ");
    stop = intInput("Enter the stop number: ");
    crossoverType = crossoverMenu();

    // Set default value for plot X axios
    plotLen = stop;

    // Best solutions array
    bestSolves = (int *) calloc(stop, sizeof(int));

    // Elites
    eliteNum = ceil(populationLen * ELITE_PERCENT);

    // Make initial population
    population = setQueensSol(populationLen, chromosomeLen);

    for (int i = 0; i < stop; i++) {

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

//    printCustomMatrix(populationLen, chromosomeLen, population, true);
//    printArray(populationLen, evaluatedArr, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);

    // Plot
    plotPY(bestSolves, plotLen + 1);
}