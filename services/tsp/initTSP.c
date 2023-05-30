#include "../../headers/sharedLib.h"
#include "../../headers/makers.h"

// get the number of cities to initiate the problem
int getTSPInitValues();

void tspPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx);

int getTSPInitValues() {
    int citiesNum = 0;

    printf("Enter the number of cities: ");
    scanf("%d", &citiesNum);

    return citiesNum;
}

void tspPopulationMaker(size_t populationNum, size_t childShare, int *sharedMem, int startIdx) {
    int *tempChromosome, elemIdx;

    for (int i = 0; i < childShare; i++) {

        // Find the element on main diameter on each chromosome.
        elemIdx = startIdx / populationNum;

        // Produce a chromosome
        tempChromosome = chromosomeMaker(populationNum, false, true);

        // make main diameter zero (moving non-zero elements on main diameter to zero element)
        for (int j = 0; j < populationNum; j++) {
            if (tempChromosome[elemIdx] == 0) continue;


            // tempChromosome[elemIdx] == element on main diameter | tempChromosome[j] == zero element
            if (tempChromosome[j] == 0)
                swap(tempChromosome, j, elemIdx);
        }

        // Add chromosome to shared memory
        for (int j = 0; j < populationNum; j++)
            sharedMem[startIdx + j] = tempChromosome[j];

        startIdx = startIdx + populationNum;

        free(tempChromosome);
    }
}