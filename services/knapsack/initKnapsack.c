#include "../../headers/mainHeaders.h"
#include "../../functions/makeBin.c"

struct knapsackInitValues {
    int n;
    int wMax;
    int *wArr;
    int *vArr;
};

// get the number of cities to initiate the problem
struct knapsackInitValues getKnapsackInitValues();

// set data structure
void setKnapsackSol(struct knapsackInitValues initValues);

struct knapsackInitValues getKnapsackInitValues() {
    struct knapsackInitValues knapsackStruct;

    // get the number of products (n)
    printf("Enter the number of products: ");
    scanf("%d", &knapsackStruct.n);

    // get maximum weight of backpack (wMax)
    printf("Enter the maximum weight of backpack (KG): ");
    scanf("%d", &knapsackStruct.wMax);

    // fill wArr (Weight Array) randomly
    knapsackStruct.wArr = makePerm(knapsackStruct.wMax);

    // fill vArr (Value Array) randomly. To be more realistic, divide values.
    knapsackStruct.vArr = makePerm(knapsackStruct.wMax / 2);

    return knapsackStruct;
}

void setKnapsackSol(struct knapsackInitValues initValues) {
    int *row, n = initValues.n;
    int *sol = (int *) calloc(n * n, sizeof(int));

    for (int i = 0; i < n; i++) {
        row = makeBin(n);

        for (int j = 0; j < n; j++) {
            sol[i * n + j] = row[j];
        }
    }

    printArray(n, initValues.wArr, "Weight: ");
    printArray(n, initValues.vArr, "Value: ");

    printMatrix(n, sol);
}
