#include "./initQueens.c"
#include "./evalQueens.c"
#include "../../headers/sharedMenu.h"
#include "../../headers/crossover.h"

void queensMain() {
    int chromosomeLen, populationLen, *population = NULL, *evaluatedArr = NULL, *bestParentsIdx = NULL, *firstChild = NULL, *secondChild = NULL,
            crossoverType;

    // Get initial values
    chromosomeLen = intInput("Enter the length of a chromosome: ");
    populationLen = intInput("Enter the length of population: ");
    crossoverType = crossoverMenu();

    if (chromosomeLen < 4) {
        printf("\nMinimum queens must be 4 or upper\n");
        return;
    }

    // make initial population
    population = setQueensSol(populationLen, chromosomeLen);

    // evaluating made population
    evaluatedArr = evalQueens(population, chromosomeLen);

    // The best parent selection
    bestParentsIdx = parentSelection(evaluatedArr, chromosomeLen, false);

    // Re-allocate memory to children based on population size
    firstChild = calloc(chromosomeLen, sizeof(int));
    secondChild = calloc(chromosomeLen, sizeof(int));

    if (crossoverType == 1) {
        // Crossover based on two breaking points
        crossover2P(
                &population[bestParentsIdx[0] * chromosomeLen],
                &population[bestParentsIdx[1] * chromosomeLen],
                chromosomeLen,
                false,
                firstChild,
                secondChild
        );
    } else {
        crossoverUni(
                &population[bestParentsIdx[0] * chromosomeLen],
                &population[bestParentsIdx[1] * chromosomeLen],
                chromosomeLen,
                false,
                firstChild,
                secondChild
        );
    }

    printArray(chromosomeLen, firstChild, "First Child: ", ANSI_COLOR_RESET);
    printArray(chromosomeLen, secondChild, "Second Child: ", ANSI_COLOR_RESET);

    printCustomMatrix(populationLen, chromosomeLen, population, true);

    printArray(chromosomeLen, evaluatedArr, "Evaluation (Collisions are counted): ", ANSI_COLOR_RESET);
}