#include "../../includes/sharedLib.h"
#include "../../includes/services/tsp.h"
#include "../../includes/types/generalTypes.h"
#include "../../includes/assets.h"
#include "../../includes/makers.h"
#include "../../includes/sharedMenu.h"
#include "../../includes/sharedMemory.h"
#include "../../includes/multiproseccing/multiprocessor.h"
#include "../../includes/sharedMacros.h"
#include "../../plot/plotPY.h"
#include "../../includes/printing.h"

void tspMain() {
    int chromosomeLen, populationLen, iteration, crossoverType, eliteLen, *population = NULL, *disMatrix = NULL, *evalResult = NULL,
            *evalSortedIdx = NULL, *newPop = NULL, *bestSolves = NULL, bestEvalIdx, genTypeSize = sizeof(int);
    time_t start, end;

    char answerLabel[SPRINTF_STRING_LEN];

    SharedMenuType inputs;

    // Get the number of cities
    inputs = sharedInitInputs();
    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, genTypeSize);

    // Get the number of chromosomes which must move to new population directly
    eliteLen = ceil(populationLen * ELITE_PERCENT);

    time(&start);

    // Produce init population by multi processes for TSP
    livePrinter("Please Wait ==> Initial population is creating...", -1, ANSI_COLOR_BLUE, NULL, false);
    population = (int *) multiprocessor(
            populationLen,
            chromosomeLen,
            populationLen * chromosomeLen,
            genTypeSize,
            &tspPopulationMaker,
            0
    );
    livePrinter("Initial population successfully created", -1, ANSI_COLOR_GREEN, NULL, true);

    // Produce DIS (Distance matrix) by multi processes
    livePrinter("Please Wait ==> Distances Matrix is creating...", -1, ANSI_COLOR_BLUE, NULL, false);
    disMatrix = (int *) multiprocessor(
            chromosomeLen,
            chromosomeLen,
            chromosomeLen * chromosomeLen,
            genTypeSize,
            &tspDisMaker,
            0
    );
    livePrinter("Distances Matrix successfully created", -1, ANSI_COLOR_GREEN, NULL, true);

    /* IMPORTANT => Stop condition of this problem is the number of loop (iteration) */

    for (int i = 0; i < iteration; i++) {

        livePrinter("Crossover live counter", i, ANSI_COLOR_RESET, ANSI_COLOR_GREEN, false);

        // Evaluation
        evalResult = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                populationLen,
                genTypeSize,
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
                genTypeSize,
                &crossover,
                7,
                population,
                evalResult,
                evalSortedIdx,
                false,
                false,
                crossoverType,
                eliteLen
        );

        // Mutation (Tweak)
        tweak(newPop, chromosomeLen, populationLen, eliteLen);

        // Save the best answer
        bestEvalIdx = evalSortedIdx[0];

        free(evalSortedIdx);

        memoryUnmap(evalResult, populationLen, genTypeSize);
        memoryUnmap(population, populationLen * chromosomeLen, genTypeSize);

        // Re-Take the new population
        population = newPop;
    }

    time(&end);

    // Hide same values on answer array
    hideSameValue(bestSolves, &iteration);

    sprintf(answerLabel, "Solved: (%d, %d)", iteration - MORE_SAME_RESULT_NUM,
            bestSolves[iteration - MORE_SAME_RESULT_NUM]);

    // Print answer
    printArray(chromosomeLen, &population[bestEvalIdx * chromosomeLen], "Answer: ", ANSI_COLOR_MAGENTA);

    showTime(end - start);

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