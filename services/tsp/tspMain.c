#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../types/GeneralTypes.h"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMacros.h"
#include "../../plot/plot.h"

void tspMain() {
    int chromosomeLen, populationLen, iteration, crossoverType, eliteNum, *population = NULL, *disMatrix = NULL, *evalResult = NULL,
            *evalSortedIdx = NULL, *newPop = NULL, plotLen, *bestSolves = NULL;

    SharedMenuType inputs;

    // Get the number of cities
    inputs = sharedInitInputs();
    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    // Set default value for plot X axios
    plotLen = iteration;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Get the number of chromosomes which must move to new population directly
    eliteNum = ceil(populationLen * ELITE_PERCENT);

    // Produce init population by multi processes for TSP
    population = (int *) multiprocessor(
            populationLen,
            chromosomeLen,
            populationLen * chromosomeLen,
            &tspPopulationMaker,
            0
    );

    // Produce DIS (Distance matrix) by multi processes
    disMatrix = (int *) multiprocessor(
            chromosomeLen,
            chromosomeLen,
            chromosomeLen * chromosomeLen,
            &tspDisMaker,
            0
    );

    /* IMPORTANT => Stop condition of this problem is the number of loop (iteration) */

    for (int i = 0; i < iteration; i++) {

        // Evaluation
        evalResult = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                populationLen,
                &evalTSPPopulation,
                2,
                population,
                disMatrix
        );

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        // Add each loop's best solve result to best array
        bestSolves[i] = evalResult[evalSortedIdx[0]];

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

        // Mutation (Tweak)
        tweak(newPop, chromosomeLen, populationLen);

        // Re-Take the new population
        population = newPop;
    }

//    printCustomMatrix(populationLen, chromosomeLen, population, true);
//    printMatrix(chromosomeLen, disMatrix, true);

//    printArray(populationLen, evalResult, "Evaluation (Distances): ", ANSI_COLOR_RESET);

    plotPY(bestSolves, plotLen, "-", "r", "TSP Problem", "Cost", "Iteration");
}