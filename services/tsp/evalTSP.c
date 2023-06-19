#include "../../headers/sharedLib.h"

// Make array of evaluation of population
void
evalTSPPopulation(size_t chromosomeLen, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args) {
    int *population = NULL, *dis = NULL, sum, currentChromosomeStartIdx, currentPosition, currentGen, nextGen;

    // Get Population matrix
    population = va_arg(args,
    int*);

    // Get dis matrix
    dis = va_arg(args,
    int*);

    for (int i = 0; i < childShare; i++) {
        sum = 0;
        currentChromosomeStartIdx = startIdx + (i * chromosomeLen);

        // Map on each sol
        for (int j = 0; j < chromosomeLen - 1; j++) {
            currentPosition = currentChromosomeStartIdx + j;

            currentGen = population[currentPosition];
            nextGen = population[currentPosition + 1];

            sum += dis[(currentGen * chromosomeLen) + nextGen];
        }

        // Finally, add first gen (element) of last chromosome. (Element of Last Row and First Column)
        sum += dis[(nextGen * chromosomeLen) + population[currentChromosomeStartIdx]];

        sharedMem[(startIdx / chromosomeLen) + i] = sum;
    }
}