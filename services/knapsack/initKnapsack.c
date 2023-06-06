#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"
#include "../../structs/knapsackStruct.h"

// set full information struct
struct KnapsackInitValues getKnapsackStructInfo(size_t productsNum, size_t wMax) {
    struct KnapsackInitValues knapsackStruct;

    knapsackStruct.n = productsNum;
    knapsackStruct.wMax = wMax;

    // fill wArr (Weight Array) randomly
    knapsackStruct.wArr = chromosomeMaker(knapsackStruct.wMax / 2, false, false, knapsackStruct.n, 1, 0);

    // fill vArr (Value Array) randomly. To be more realistic, divide values.
    knapsackStruct.vArr = chromosomeMaker(knapsackStruct.wMax / 2, false, false, knapsackStruct.n, 0);

    return knapsackStruct;
}

void knapsackPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx, size_t argsNum,
                             va_list args) {
    int *tempChromosome;

    for (int i = 0; i < childShare; i++) {

        // Produce a BINARY chromosome
        tempChromosome = chromosomeMaker(populationNum, true, false, -1, 0);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[startIdx + j] = tempChromosome[j];

        startIdx = startIdx + populationNum;

        free(tempChromosome);
    }

    va_end(args);
}