#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void showServices() {
    char servicesName[SERVICES_LEN][10] = {"TSP", "Knapsack", "N-Queens", "Exit"};

    puts("Hello\nThis program is created by \"Yasin Gourkani\"\tStudent ID:\"9974359\"\nShiraz University\n");
    puts("E-Mail: yassingourkani@outlook.com\n");
    puts("Application Menu: \n");

    for (int i = 0; i < SERVICES_LEN; i++)
        printf("\t%d- %s\n", i + 1, servicesName[i]);
}
