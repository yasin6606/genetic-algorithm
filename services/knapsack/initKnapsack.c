#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"
#include "../../structs/knapsackStruct.h"

// set full information struct
struct KnapsackInitValues getKnapsackStructInfo(size_t productsNum, size_t wMax);

// set data structure
int *setKnapsackSol(size_t productsNum);

struct KnapsackInitValues getKnapsackStructInfo(size_t productsNum, size_t wMax) {
    struct KnapsackInitValues knapsackStruct;

    knapsackStruct.n = productsNum;
    knapsackStruct.wMax = wMax;

    // fill wArr (Weight Array) randomly
    knapsackStruct.wArr = makePerm(knapsackStruct.wMax / 2, true, knapsackStruct.n, 1, 0);

    // fill vArr (Value Array) randomly. To be more realistic, divide values.
    knapsackStruct.vArr = makePerm(knapsackStruct.wMax / 2, true, knapsackStruct.n, 0);

    return knapsackStruct;
}

int *setKnapsackSol(size_t productsNum) {
    int *sol = NULL;
    int *solMatrix = (int *) calloc(productsNum * productsNum, sizeof(int));

    for (int i = 0; i < productsNum; i++) {
        sol = makeBin(productsNum);

        for (int j = 0; j < productsNum; j++)
            solMatrix[i * productsNum + j] = sol[j];
    }

    return solMatrix;
}
