#include "../includes/sharedLib.h"
#include "../includes/makers.h"

/*
 * Two breaking points VS Uniform:
 * crossover2P generates two new different chromosomes based on two breaking points which the first point always should be smaller
 * than the second one and the difference between points must be greater than 1 so as to avoid getting two same points.
 * Moreover, this function give an argument that is called ignorePerm which define new chromosomes should be permutation or not.
 * Also, There is a mask array which is a binary array to generate a new child based on Uniform algorithm; By using this type of
 * generating algorithm, it will select gens which are masked on 1 from one parent and 0 on another parent. As well as, there is a
 * checking code so as to produce a permutation child based on ignorePerm's value.
 * */

void crossover(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args) {
    int realRow, logicalRow, *bestParentsIdx = NULL, *breakPoints = NULL, *mask = NULL, *newChild = NULL, *population = NULL, *evalResult = NULL,
            *evalSortedIdx = NULL, ignorePerm, type, crossoverType, elitesNum, *parent1 = NULL, *parent2 = NULL;

    // Last population
    population = va_arg(args,
    int *);

    // Last evaluation result
    evalResult = va_arg(args,
    int* );

    // Sorted last evaluation result in order to move some of them (4%) which must directly add to new population.
    evalSortedIdx = va_arg(args,
    int* );

    // Controller to ignore permutation or not
    ignorePerm = va_arg(args,
    int);

    // Define the problem type, Maximum or Minimum type
    type = va_arg(args,
    int);

    // Controller so as to generate new children based on crossover type
    crossoverType = va_arg(args,
    int);

    // The number of elite chromosomes which must directly move to new population
    elitesNum = va_arg(args,
    int);

    for (int i = 0; i < childShare; i++) {
        realRow = startIdx + (i * chromosomeLen);
        logicalRow = realRow / chromosomeLen;

        // Add those chromosomes which must directly move to the new population.
        if (logicalRow < elitesNum) {
            for (int j = 0; j < chromosomeLen; j++)
                sharedMem[realRow + j] = population[(evalSortedIdx[i] * chromosomeLen) + j];

            continue;
        }

        // Selection parents based on K-Competition algorithm
        bestParentsIdx = parentSelection(evalResult, chromosomeLen, type);

        // Parents
        parent1 = &population[bestParentsIdx[0] * chromosomeLen];
        parent2 = &population[bestParentsIdx[1] * chromosomeLen];

        // Crossover
        if (crossoverType == 1) { // Two breaking points

            // Get break points
            breakPoints = breakPointGenerator(chromosomeLen);

            // Generate a new child (chromosome)
            newChild = childGenerator2P(chromosomeLen, ignorePerm, breakPoints, parent1, parent2);

            free(breakPoints);
        } else { // Uniform

            // Generate a mask array so as to produce a new child
            mask = chromosomeMaker(chromosomeLen, true, false, -1, 0, NULL);

            // Generate a new child (chromosome)
            newChild = childGeneratorUni(chromosomeLen, ignorePerm, mask, parent1, parent2);

            free(mask);
        }

        // Add a new generated child to new population
        for (int j = 0; j < chromosomeLen; j++)
            sharedMem[realRow + j] = newChild[j];

        free(newChild);
        free(bestParentsIdx);
    }

    free(evalSortedIdx);
}