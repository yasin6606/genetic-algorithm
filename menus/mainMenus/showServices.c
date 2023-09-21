#include "../../includes/sharedLib.h"
#include "../../includes/sharedMacros.h"

void showServices() {
    char servicesName[SERVICES_LEN][10] = {"TSP", "Knapsack", "N-Queens", "Exit"};

    printf("Hello\t%s\n\n", __DATE__);

    printf(
            "This program is created by %sYasin Gourkani%s\tStudent ID: %s9974359%s\n\nUniversity: %sShiraz University%s\n\n",
            ANSI_COLOR_BLUE,
            ANSI_COLOR_RESET,
            ANSI_COLOR_BLUE,
            ANSI_COLOR_RESET,
            ANSI_COLOR_YELLOW,
            ANSI_COLOR_RESET
    );

    printf("E-Mail: %syassingourkani@outlook.com%s\n\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);

    printf(
            "%s(ATTENTION)%s This program is running on Multi-Process mode!%s\n\n",
            ANSI_COLOR_RED,
            ANSI_COLOR_BLUE,
            ANSI_COLOR_RESET
    );

    printf("Application Menu: \n\n");

    for (int i = 0; i < SERVICES_LEN; i++)
        printf("\t%s%d%s- %s\n", ANSI_COLOR_BLUE, i + 1, ANSI_COLOR_RESET, servicesName[i]);
}
