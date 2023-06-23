#include "./initKnapsack.c"
#include "./evalKnapsack.c"
#include "../../types/GeneralTypes.h"
#include "../../headers/sharedMenu.h"
#include "../../plot/plot.h"
#include "../../headers/printing.h"

void knapsackMain() {
    int chromosomeLen, populationLen, iteration, crossoverType, wMax, *wArr = NULL, *vArr = NULL, eliteNum, *population = NULL,
            *evalResult = NULL, *evalSortedIdx = NULL, *bestSolves = NULL, *newPop = NULL;

    char answerLabel[SPRINTF_STRING_LEN];

    SharedMenuType inputs;

    // Get initial values
    wMax = intInput("Enter the maximum weight of knapsack: ");

    inputs = sharedInitInputs();

    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Elites
    eliteNum = ceil(iteration * ELITE_PERCENT);

    // Fill wArr (Weight Array) randomly
    wArr = makePerm(chromosomeLen, true, chromosomeLen, 1, 0);

    // Fill vArr (Value Array) randomly. To be more realistic, divide values.
    vArr = makePerm(chromosomeLen, true, chromosomeLen, 0);

    // Produce init population
    population = makeKnapsackPopulation(populationLen, chromosomeLen);

    for (int i = 0; i < iteration; i++) {

        // Evaluate
        evalResult = evalKnapsack(population, populationLen, chromosomeLen, wMax, wArr, vArr);

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        // Reverse evaluated indexes array since Knapsack problem is a maximum type problem
        reverseArray(evalSortedIdx, populationLen);

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
                true,
                true,
                crossoverType
        );

        // Mutation (Tweak)
        tweak(newPop, populationLen, chromosomeLen);

        // Re-Take new population
        population = newPop;
    }

    // Print valid Weights and Values array
    printArray(chromosomeLen, wArr, "Weight: ", ANSI_COLOR_GREEN);
    printArray(chromosomeLen, vArr, "Value: ", ANSI_COLOR_GREEN);

    // Hide constant part of the answer
    hideSameValue(bestSolves, &iteration);

    sprintf(answerLabel, "Solved: (%d, %d)", iteration - MORE_SAME_RESULT_NUM,
            bestSolves[iteration - MORE_SAME_RESULT_NUM]);

    // Print answer
    if (evalSortedIdx)
        printArray(chromosomeLen, &population[evalSortedIdx[0]], "Answer: ", ANSI_COLOR_MAGENTA);

    // Plot
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