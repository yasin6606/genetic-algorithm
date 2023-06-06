#include "../../headers/sharedLib.h"

// make array of evaluation of Sol matrix
void evalKnapsack(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args);

// evaluate each Sol
int evalSolKnapsack(const int *sol, size_t populationNum, size_t wMax, int *wArr, int *vArr);

void evalKnapsack(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum, va_list args) {
    int wMax, *wArr, *vArr, *populationMatrix;

    // ! ! ! (Attention) The order of getting data from variadic is highly IMPORTANT. The order MUST BE same as sending.

    // Get maximum weight of knapsack
    wMax = va_arg(args,
    int);

    // TODO: Incoming pointers should be packed by a Loop.
    // Get array of product's weights
    wArr = va_arg(args,
    int*);

    // Get array of product's values
    vArr = va_arg(args,
    int*);

    // Get array of product's values
    populationMatrix = va_arg(args,
    int*);

    for (int i = 0; i < childShare; i++)
        sharedMem[i + (startIdx / populationNum)] = evalSolKnapsack(
                &populationMatrix[startIdx + (i * populationNum)],
                populationNum,
                wMax,
                wArr,
                vArr
        );
}

int evalSolKnapsack(const int *sol, size_t populationNum, size_t wMax, int *wArr, int *vArr) {
    int tempWeight = 0, tempValue = 0;

    // Find elements that are 1 and mask it on each sol array
    for (int i = 0; i < populationNum; i++) {
        if (sol[i] == 0) continue;

        // Make the sum of each sol weights
        tempWeight += wArr[i];

        // Make the sum of each sol values
        tempValue += vArr[i];

        // Throw out each sol which has more weight than knapsack's maximum weight and make its value 0
        if (tempWeight > wMax) {
            tempValue = 0;

            break;
        }
    }

    return tempValue;
}