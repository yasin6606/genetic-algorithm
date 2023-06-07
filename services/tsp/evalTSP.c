#include "../../headers/sharedLib.h"

// Make array of evaluation of population
void
evalTSPPopulation(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args) {
    int *population = NULL, *dis = NULL, sum, row, col;

    // Get Population matrix
    population = va_arg(args,
    int*);

    // Get dis matrix
    dis = va_arg(args,
    int*);

    for (int i = 0; i < childShare; i++) {
        sum = 0;

        // Map on each sol
        for (int j = 0; j < populationNum - 1; j++) {
            row = population[(startIdx + (i * populationNum)) + j] * populationNum;
            col = population[((startIdx + (i * populationNum)) + j) + 1];

            sum += dis[row + col];
        }

        // Finally, add first gen (element) of last chromosome. (Element of Last Row and First Column)
        sum += dis[(populationNum - 1) * populationNum];

        sharedMem[(startIdx / populationNum) + i] = sum;
    }
}