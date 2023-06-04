#include "../../headers/sharedLib.h"
#include "../../headers/sharedMacros.h"

size_t crossoverMenu() {
    size_t temp;
    char *items[CROSSOVER_TYPE_LEN] = {"Two breaking points", "Uniform"};

    printf("\nCrossover menu:\n");

    for (int i = 0; i < CROSSOVER_TYPE_LEN; i++)
        printf("\t%s%d%s- %s\n", ANSI_COLOR_BLUE, i + 1, ANSI_COLOR_RESET, items[i]);

    printf("\nEnter crossover type: ");
    scanf("%zu", &temp);
    puts("");

    return temp;
}