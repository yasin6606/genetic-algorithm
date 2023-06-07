#include "../../headers/sharedLib.h"
#include "../../headers/assistant.h"
#include "../../headers/makers.h"

int *tspPopulationMaker(size_t populationNum) {
    int *arr = (int *) calloc(populationNum * populationNum, sizeof(int)), *tempChromosome;

    for (int i = 0; i < populationNum; i++) {

        // Produce a chromosome
        tempChromosome = makePerm(populationNum, false, -1, 0);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            arr[i * populationNum + j] = tempChromosome[j];

        free(tempChromosome);
    }

    return arr;
}

int *tspDisMaker(size_t populationNum) {
    int *disArr = (int *) calloc(populationNum * populationNum, sizeof(int)), *randArr = NULL;

    for (int i = 0; i < populationNum; i++) {
        randArr = makePerm(populationNum, false, -1, 0);

        // make main diameter zero (moving non-zero elements on main diameter to zero element)
        for (int j = 0; j < populationNum; j++) {
            if (randArr[i] == 0) continue;

            // randArr[i] == element on main diameter | randArr[j] == zero element
            if (randArr[j] == 0)
                swap(randArr, j, i);
        }

        // make DIS matrix
        for (int j = 0; j < populationNum; j++)
            disArr[i * populationNum + j] = randArr[j];
    }

    return disArr;
}