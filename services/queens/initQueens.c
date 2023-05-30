#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

// get the number of queens to initiate the problem
int getQueensInitValues();

void queensPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx);

int getQueensInitValues() {
    int n;

    // get the number of products (n)
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    return n;
}

void queensPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx) {
    int *tempChromosome;

    for (int i = 0; i < childShare; i++) {

        // Produce a chromosome
        tempChromosome = chromosomeMaker(populationNum, false, true);

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[startIdx + j] = tempChromosome[j];

        startIdx = startIdx + populationNum;

        free(tempChromosome);
    }
}