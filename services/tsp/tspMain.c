#include "../../services/tsp/initTSP.c"
#include "./evalTSP.c"
#include "../../headers/printing.h"
#include "../../headers/sharedMenu.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMacros.h"
#include "../../plot/plot.h"

void tspMain() {
    int chromosomeLen, populationLen, stop, crossoverType, eliteNum, *population = NULL, *disMatrix = NULL, *evalResult = NULL,
            *evalSortedIdx = NULL, *newPop = NULL, plotLen, *bestSolves = NULL;

    // Get the number of cities
    chromosomeLen = intInput("Enter the number of Cities (Each chromosome's gens): ");
    populationLen = intInput("Enter the length of population: ");
    stop = intInput("Enter the number of loops: ");
    crossoverType = crossoverMenu();

    // Set default value for plot X axios
    plotLen = stop;

    // Best solutions array
    bestSolves = (int *) calloc(stop, sizeof(int));

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

    /* IMPORTANT => Stop condition of this problem is the number of loop (stop) */

    for (int i = 0; i < stop; i++) {

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

    plotPY(bestSolves, plotLen);
}