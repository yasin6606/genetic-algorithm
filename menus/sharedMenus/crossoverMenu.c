#include "../../headers/sharedLib.h"
#include "../../headers/sharedMacros.h"

size_t crossoverMenu() {
    size_t temp;
    char *items[CROSSOVER_TYPE_LEN] = {"Two breaking points", "Uniform"};

    printf("\nCrossover menu:\n");
    fflush(stdout);

    for (int i = 0; i < CROSSOVER_TYPE_LEN; i++)
        printf("\t%s%d%s- %s\n", ANSI_COLOR_BLUE, i + 1, ANSI_COLOR_RESET, items[i]);

    printf("\nEnter crossover type: %s", ANSI_COLOR_CYAN);
    fflush(stdout);
    scanf("%zu", &temp);
    printf("%s", ANSI_COLOR_RESET);
    puts("");

    return temp;
}