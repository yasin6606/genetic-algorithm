#include "../../headers/sharedLib.h"

size_t crossoverMenu() {
    size_t temp;

    printf("\nCrossover menu:\n\t1.Two breaking points\n\t2.Uniform\n\n");
    printf("Enter crossover type: ");
    scanf("%zu", &temp);
    puts("");

    return temp;
}