#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"
#include "../../structs/knapsackStruct.h"

// get the number of cities to initiate the problem
struct KnapsackInitValues getKnapsackInitValues();

void knapsackPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx);

struct KnapsackInitValues getKnapsackInitValues() {
    struct KnapsackInitValues knapsackStruct;

    // get the number of products (n)
    printf("Enter the number of products: ");
    scanf("%d", &knapsackStruct.n);

    // get maximum weight of backpack (wMax)
    printf("Enter the maximum weight of backpack (KG): ");
    scanf("%d", &knapsackStruct.wMax);

    // fill wArr (Weight Array) randomly
    knapsackStruct.wArr = chromosomeMaker(knapsackStruct.n, false, false);

    // fill vArr (Value Array) randomly. To be more realistic, divide values.
    knapsackStruct.vArr = chromosomeMaker(knapsackStruct.n, false, false);

    return knapsackStruct;
}

void knapsackPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx) {
    int *tempChromosome;

    for (int i = 0; i < childShare; i++) {

        // Produce a chromosome
        tempChromosome = chromosomeMaker(populationNum, true, false);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[startIdx + j] = tempChromosome[j];

        startIdx = startIdx + populationNum;

        free(tempChromosome);
    }
}
