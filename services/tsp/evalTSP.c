#include "../../headers/sharedLib.h"

// Make array of evaluation of population
int *evalTSPPopulation(size_t populationNum, int *disMatrix, int *populationMatrix) {
    int sum, *sol = NULL, *arr = (int *) calloc(populationNum, sizeof(int));

    for (int i = 0; i < populationNum; i++) {
        sum = 0;

        // Each chromosome
        sol = &populationMatrix[i * populationNum];

        // Select row and col on DIS matrix
        for (int j = 0; j < populationNum - 1; j++)
            sum += disMatrix[(sol[j] * populationNum) + sol[j + 1]];

        // Finally, add first gen (element) of last chromosome. (Element of Last Row and First Column)
        sum += disMatrix[(populationNum - 1) * populationNum];

        arr[(i / populationNum) + i] = sum;
    }

    return arr;
}