#include "../../includes/sharedLib.h"
#include "../../includes/assets.h"
#include "../../includes/services/knapsack.h"
#include "../../includes/makers.h"
#include "../../includes/sharedMemory.h"
#include "../../includes/multiproseccing/multiprocessor.h"
#include "../../includes/sharedMacros.h"
#include "../../includes/sharedMenu.h"
#include "../../plot/plotPY.h"
#include "../../includes/printing.h"

void knapsackMain() {
    int chromosomeLen, populationLen, iteration, crossoverType, eliteLen, wMax, *wArr, *vArr, *population = NULL,
            *evalResult = NULL, *evalSortedIdx = NULL, *newPop = NULL, *bestSolves = NULL, bestEvalIdx,
            ignoredArr[ONE_LEN] = {0};

    char answerLabel[SPRINTF_STRING_LEN];

    SharedMenuType inputs;

    // Get initial values
    wMax = intInput("Enter the maximum weight of knapsack: ");
    inputs = sharedInitInputs();

    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    // Fill wArr (Weight Array) randomly
    wArr = chromosomeMaker(chromosomeLen, false, false, chromosomeLen, ONE_LEN, ignoredArr);

    // Fill vArr (Value Array) randomly. To be more realistic, divide values.
    vArr = chromosomeMaker(chromosomeLen, false, false, chromosomeLen, 0, NULL);

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Get the number of chromosomes which must move to new population directly
    eliteLen = ceil(populationLen * ELITE_PERCENT);

    // Produce init population by multi processes for Knapsack
    livePrinter("Please Wait ==> Initial population is creating...", -1, ANSI_COLOR_BLUE, NULL, false);
    population = (int *) multiprocessor(
            populationLen,
            chromosomeLen,
            sizeof(int),
            populationLen * chromosomeLen,
            &knapsackPopulationMaker,
            0
    );
    livePrinter("Initial population successfully created", -1, ANSI_COLOR_GREEN, NULL, true);

    /* IMPORTANT => Stop condition of this problem is the number of iteration */

    for (int i = 0; i < iteration; i++) {

        livePrinter("Crossover live counter", i, ANSI_COLOR_RESET, ANSI_COLOR_GREEN, false);

        // Evaluation
        evalResult = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                sizeof(int),
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
                sizeof(int),
                populationLen * chromosomeLen,
                &crossover,
                7,
                population,
                evalResult,
                evalSortedIdx,
                true,
                true,
                crossoverType,
                eliteLen
        );

        // Mutation (Tweak)
        tweak(newPop, chromosomeLen, populationLen, eliteLen);

        // Save the best answer
        bestEvalIdx = evalSortedIdx[0];

        free(evalSortedIdx);

        memoryUnmap(evalResult, populationLen, sizeof(int));
        memoryUnmap(population, populationLen * chromosomeLen, sizeof(int));

        // Re-Take the new population
        population = newPop;
    }

    printArray(chromosomeLen, wArr, "Weight: ", ANSI_COLOR_BLUE);
    printArray(chromosomeLen, vArr, "Value: ", ANSI_COLOR_BLUE);

    // Hide same values on answer array
    hideSameValue(bestSolves, &iteration);

    sprintf(answerLabel, "Solved: (%d, %d)", iteration - MORE_SAME_RESULT_NUM,
            bestSolves[iteration - MORE_SAME_RESULT_NUM]);

    // Print answer
    printArray(chromosomeLen, &population[bestEvalIdx * chromosomeLen], "Answer: ", ANSI_COLOR_MAGENTA);

    plotPY(
            bestSolves,
            iteration,
            "-",
            "m",
            "Knapsack Problem",
            "Value",
            "Iteration",
            answerLabel
    );
}