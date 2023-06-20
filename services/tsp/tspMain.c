#include "./initTSP.c"
#include "./evalTSP.c"
#include "../../types/GeneralTypes.h"
#include "../../headers/sharedMenu.h"
#include "../../plot/plot.h"

void tspMain() {
    int chromosomeLen, populationLen, iteration, eliteNum, *population = NULL, *disMatrix = NULL, *evalResult = NULL,
            *bestSolves = NULL, *evalSortedIdx = NULL, crossoverType, *newPop = NULL;

    SharedMenuType inputs;

    // Get initial values
    inputs = sharedInitInputs();

    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Elites
    eliteNum = ceil(populationLen * ELITE_PERCENT);

    // Produce init population
    population = tspPopulationMaker(populationLen, chromosomeLen);

    // Produce Distances matrix
    disMatrix = tspDisMaker(chromosomeLen);

    for (int i = 0; i < iteration; i++) {

        // Evaluate
        evalResult = evalTSPPopulation(populationLen, chromosomeLen, disMatrix, population);

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        // Add each loop's best solve result to best array
        bestSolves[i] = evalResult[evalSortedIdx[0]];

        // Crossover (Re-Produce a new generation (population))
        newPop = crossover(
                populationLen,
                chromosomeLen,
                population,
                eliteNum,
                evalSortedIdx,
                evalResult,
                false,
                false,
                crossoverType
        );

        // Mutation (Tweak)
        tweak(newPop, populationLen, chromosomeLen);

        // Re-Take new population
        population = newPop;
    }

    plotPY(bestSolves, iteration, "-", "r", "Traveler Salesman Problem", "Cost", "Iteration");
}