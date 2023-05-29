#include "../../headers/sharedLib.h"
#include "../../functions/makeBin.c"
#include "../../structs/knapsackStruct.h"

// get the number of cities to initiate the problem
struct KnapsackInitValues getKnapsackInitValues();

// set data structure
int *setKnapsackSol(struct KnapsackInitValues initValues);

struct KnapsackInitValues getKnapsackInitValues() {
    struct KnapsackInitValues knapsackStruct;

    // get the number of products (n)
    printf("Enter the number of products: ");
    scanf("%d", &knapsackStruct.n);

    // get maximum weight of backpack (wMax)
    printf("Enter the maximum weight of backpack (KG): ");
    scanf("%d", &knapsackStruct.wMax);

    // fill wArr (Weight Array) randomly
    knapsackStruct.wArr = makePerm(knapsackStruct.wMax / 2);

    // fill vArr (Value Array) randomly. To be more realistic, divide values.
    knapsackStruct.vArr = makePerm(knapsackStruct.wMax / 2);

    return knapsackStruct;
}

int *setKnapsackSol(struct KnapsackInitValues initValues) {
    int *sol = NULL;
    size_t n = initValues.n;
    int *solMatrix = (int *) calloc(n * n, sizeof(int));

    for (int i = 0; i < n; i++) {
        sol = makeBin(n);

        for (int j = 0; j < n; j++)
            solMatrix[i * n + j] = sol[j];
    }

    return solMatrix;
}
