#include "../../headers/sharedLib.h"
#include "../../structs/knapsackStruct.h"

// make array of evaluation of Sol matrix
int *evalKnapsack(const int *matrix, struct KnapsackInitValues knapsackStruct);

// evaluate each Sol
int eval(const int *sol, struct KnapsackInitValues knapsackStruct);

int *evalKnapsack(const int *matrix, struct KnapsackInitValues knapsackStruct) {
    size_t size = knapsackStruct.n;
    int *tempArr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
        tempArr[i] = eval(&matrix[i * size], knapsackStruct);

    return tempArr;
}

int eval(const int *sol, struct KnapsackInitValues knapsackStruct) {
    size_t size = knapsackStruct.n;
    int tempWeight = 0, tempValue = 0;

    // find elements that are 1 and mask it on each sol array
    for (int i = 0; i < size; i++) {
        if (sol[i] == 0) continue;

        // Make the sum of each sol weights
        tempWeight += knapsackStruct.wArr[i];

        // Make the sum of each sol values
        tempValue += knapsackStruct.vArr[i];

        // Throw out each sol which has more weight than knapsack's maximum weight and make its value 0
        if (tempWeight > knapsackStruct.wMax) {
            tempValue = 0;

            break;
        }
    }

    return tempValue;
}