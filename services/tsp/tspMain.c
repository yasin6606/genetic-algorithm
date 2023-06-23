#include "./initTSP.c"
#include "./evalTSP.c"
#include "../../types/GeneralTypes.h"
#include "../../headers/sharedMenu.h"
#include "../../plot/plot.h"

void tspMain() {
    int chromosomeLen, populationLen, iteration, eliteNum, *population = NULL, *disMatrix = NULL, *evalResult = NULL,
            *bestSolves = NULL, *evalSortedIdx = NULL, crossoverType, *newPop = NULL;

    char answerLabel[SPRINTF_STRING_LEN];

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
    livePrinter("Please Wait ==> Initial population is creating...", -1, ANSI_COLOR_BLUE, NULL, false);
    population = tspPopulationMaker(populationLen, chromosomeLen);
    livePrinter("Initial population successfully created", -1, ANSI_COLOR_GREEN, NULL, true);

    // Produce Distances matrix
    livePrinter("Please Wait ==> Destination Matrix is creating...", -1, ANSI_COLOR_GREEN, NULL, false);
    disMatrix = tspDisMaker(chromosomeLen);
    livePrinter("Destination Matrix successfully created", -1, ANSI_COLOR_GREEN, NULL, true);

    for (int i = 0; i < iteration; i++) {

        livePrinter("Crossover live counter", i, ANSI_COLOR_RESET, ANSI_COLOR_GREEN, false);

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

    // Hide constant part of the answer
    hideSameValue(bestSolves, &iteration);

    sprintf(answerLabel, "Solved: (%d, %d)", iteration - MORE_SAME_RESULT_NUM,
            bestSolves[iteration - MORE_SAME_RESULT_NUM]);

    // Print answer
    if (evalSortedIdx)
        printArray(chromosomeLen, &population[evalSortedIdx[0]], "Answer: ", ANSI_COLOR_MAGENTA);

    plotPY(
            bestSolves,
            iteration,
            "-",
            "r",
            "Traveler Salesman Problem",
            "Cost",
            "Iteration",
            answerLabel
    );
}