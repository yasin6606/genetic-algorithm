#include "../../includes/sharedLib.h"
#include "../../includes/types/generalTypes.h"
#include "../../includes/services/queens.h"
#include "../../includes/assets.h"
#include "../../includes/makers.h"
#include "../../includes/sharedMemory.h"
#include "../../includes/sharedMenu.h"
#include "../../includes/multiproseccing/multiprocessor.h"
#include "../../includes/sharedMacros.h"
#include "../../plot/plotPY.h"
#include "../../includes/printing.h"

void queensMain() {
    int i, chromosomeLen, populationLen, iteration, crossoverType, eliteLen, *population = NULL, *evalResult = NULL, *evalSortedIdx = NULL,
            *newPop = NULL, plotLen, *bestSolves = NULL;

    char answerLabel[SPRINTF_STRING_LEN];

    SharedMenuType inputs;

    // Get the number of queens
    inputs = sharedInitInputs();
    chromosomeLen = inputs.chromosomeLen;
    populationLen = inputs.populationLen;
    iteration = inputs.iteration;
    crossoverType = inputs.crossoverType;

    if (chromosomeLen < 4) {
        SHOW_WARNING("Minimum queens must be 4 or upper")

        return;
    }

    // Set default value for plot X axios
    plotLen = iteration;

    // Best solutions array
    bestSolves = (int *) calloc(iteration, sizeof(int));

    // Get the number of chromosomes which must move to new population directly
    eliteLen = ceil(populationLen * ELITE_PERCENT);

    // Produce init population by multi processes for N-Queens
    livePrinter("Please Wait ==> Initial population is creating...", -1, ANSI_COLOR_BLUE, NULL, false);
    population = (int *) multiprocessor(
            populationLen,
            chromosomeLen,
            populationLen * chromosomeLen,
            sizeof(int),
            &queensPopulationMaker,
            0
    );
    livePrinter("Initial population successfully created", -1, ANSI_COLOR_GREEN, NULL, true);

    for (i = 0; i < iteration; i++) {

        livePrinter("Crossover live counter", i, ANSI_COLOR_RESET, ANSI_COLOR_GREEN, false);

        // Evaluation
        evalResult = (int *) multiprocessor(
                populationLen,
                chromosomeLen,
                populationLen,
                sizeof(int),
                &evalQueens,
                1,
                population
        );

        // Sort evaluated array and return indexes
        evalSortedIdx = sortChromosomes(evalResult, populationLen);

        // Add each loop's best solve result to best array
        bestSolves[i] = evalResult[evalSortedIdx[0]];

        // Stop Condition if zero collision found
        if (bestSolves[i] == 0) {
            plotLen = i;

            // Print answer
            printArray(chromosomeLen, &population[evalSortedIdx[0] * chromosomeLen], "Answer: ", ANSI_COLOR_MAGENTA);

            break;
        }

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
                false,
                false,
                crossoverType,
                eliteLen
        );

        // Tweak (Mutation)
        tweak(newPop, chromosomeLen, populationLen, eliteLen);

        free(evalSortedIdx);

        memoryUnmap(evalResult, populationLen, sizeof(int));
        memoryUnmap(population, populationLen * chromosomeLen, sizeof(int));

        // Re-Take the new population
        population = newPop;
    }

    sprintf(answerLabel, "Solved: (%d, %d)", plotLen, bestSolves[iteration - 1]);

    plotPY(
            bestSolves,
            bestSolves[iteration - 1] == 0 ? plotLen + 1 : i,
            "-",
            "b",
            "N-Queens Problem",
            "Collision",
            "Iteration",
            answerLabel
    );
}