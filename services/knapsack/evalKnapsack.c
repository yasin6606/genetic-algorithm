#include "../../headers/mainHeaders.h"

// make array of evaluation of Sol matrix
int *eval(const int *matrix, struct KnapsackInitValues knapsackStruct);

// evaluate each Sol
int evalKnapsack(const int *sol, struct KnapsackInitValues knapsackStruct);

int *eval(const int *matrix, struct KnapsackInitValues knapsackStruct) {
    int size = knapsackStruct.n, *tempArr = (int *) calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
        tempArr[i] = evalKnapsack(&matrix[i * size], knapsackStruct);

    return tempArr;
}

int evalKnapsack(const int *sol, struct KnapsackInitValues knapsackStruct) {
    int size = knapsackStruct.n, tempWeight = 0, tempValue = 0;

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