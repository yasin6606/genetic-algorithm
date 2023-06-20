#include "../../headers/sharedLib.h"
#include "../../structs/knapsackStruct.h"

int *evalKnapsack(const int *population, size_t populationLen, size_t chromosomeLen, size_t wMax, const int *wArr,
                  const int *vArr);

// Evaluate each chromosome
int eval(const int *chromosome, size_t chromosomeLen, size_t wMax, const int *wArr, const int *vArr);

int *evalKnapsack(const int *population, size_t populationLen, size_t chromosomeLen, size_t wMax, const int *wArr,
                  const int *vArr) {
    int *tempArr = (int *) calloc(populationLen, sizeof(int));

    for (int i = 0; i < populationLen; i++)
        tempArr[i] = eval(&population[i * chromosomeLen], chromosomeLen, wMax, wArr, vArr);

    return tempArr;
}

int eval(const int *chromosome, size_t chromosomeLen, size_t wMax, const int *wArr, const int *vArr) {
    int tempWeight = 0, tempValue = 0;

    // find elements that are 1 and mask it on each chromosome array
    for (int i = 0; i < chromosomeLen; i++) {
        if (chromosome[i] == 0) continue;

        // Make the sum of each chromosome weights
        tempWeight += wArr[i];

        // Make the sum of each chromosome values
        tempValue += vArr[i];

        // Throw out each chromosome which has more weight than knapsack's maximum weight and make its value 0
        if (tempWeight > wMax) {
            tempValue = 0;

            break;
        }
    }

    return tempValue;
}