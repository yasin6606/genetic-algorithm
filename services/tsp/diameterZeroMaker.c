#include "../../headers/sharedLib.h"
#include "../../headers/assets.h"

// make main diameter zero (moving non-zero elements on main diameter to zero element)
void diameterZeroMaker(int *population, size_t populationNum) {
    for (int i = 0; i < populationNum; i++)
        for (int j = 0; j < populationNum; j++) {
            if (j == i && population[(i * populationNum) + j] == 0) continue;

            // population[i] == element on main diameter | population[j] == zero element
            if (population[(i * populationNum) + j] == 0)
                swap(population, ((i * populationNum) + i), ((i * populationNum) + j));
        }
}