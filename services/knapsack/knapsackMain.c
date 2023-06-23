#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../headers/printing.h"
#include "../../headers/multiproseccing/multiprocessor.h"
#include "../../headers/sharedMacros.h"
#include "../../headers/sharedMenu.h"
#include "../../plot/plot.h"

void knapsackMain() {
    int chromosomeLen, populationLen, iteration, crossoverType, eliteNum, wMax, *wArr, *vArr, *population = NULL,
            *evalResult = NULL, *evalSortedIdx = NULL, *newPop = NULL, plotLen, *bestSolves = NULL;

    SharedMenuType inputs;

    // Get initial values
    wMax = intInput("Enter the maximum weight of knapsack: ");
    inputs = sharedInitInputs();

    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;


    // Fill wArr (Weight Array) randomly
    wArr = chromosomeMaker(chromosomeLen, false, false, chromosomeLen, 1, 0);

    // Fill vArr (Value Array) randomly. To be more realistic, divide values.
    vArr = chromosomeMaker(chromosomeLen, false, false, chromosomeLen, 0);

    // Set default value for plot X axios
    plotLen = iteration;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Get the number of chromosomes which must move to new population directly
    eliteNum = ceil(populationLen * ELITE_PERCENT);

    // Produce init population by multi processes for Knapsack
    population = (int *) multiprocessor(
            populationLen,
            chromosomeLen,
            populationLen * chromosomeLen,
            &knapsackPopulationMaker,
            0
    );

    /* IMPORTANT => Stop condition of this problem is the number of iteration */

    for (int i = 0; i < iteration; i++) {

        // Evaluation
        evalResult = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                populationLen,
                &evalKnapsack,
                4,
                wMax,
                wArr,
                vArr,
                population
        );

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        /* (Attention !) Based on this problem which needs a maximum solution, it is the most important to reverse the
         * sorted evaluation array to move the elites directly from top of the sorted evaluated array.
         */
        reverseArray(evalSortedIdx, populationLen);

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
                true,
                true,
                crossoverType,
                eliteNum
        );

        // Mutation (Tweak)
        tweak(newPop, chromosomeLen, populationLen);

        // Re-Take the new population
        population = newPop;
    }

    printArray(chromosomeLen, wArr, "Weight: ", ANSI_COLOR_MAGENTA);
    printArray(chromosomeLen, vArr, "Value: ", ANSI_COLOR_MAGENTA);

//    printCustomMatrix(populationLen, chromosomeLen, population, true);
//    printArray(populationLen, evalResult, "Evaluation (Values): ", ANSI_COLOR_RESET);

    printArray(iteration, bestSolves, "Answer: ", ANSI_COLOR_MAGENTA);

    plotPY(bestSolves, plotLen, "-", "m", "Knapsack Problem", "Value", "Iteration");
}