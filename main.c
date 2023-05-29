#include "headers/sharedLib.h"
#include "services/tsp/tspMain.c"
#include "services/knapsack/knapsackMain.c"
#include "services/queens/queensMain.c"

#define SERVICES_LEN 4

// show introduction and the list of services
void showServices();

// get the service number from showed list so as to user want to run
int getService();

// set the service so that run
void setService(int serviceNum);

int main() {
    int serviceSelected;

    /* To use rand(), it is the most important in order to use srand() JUST ONCE.
     * ! NOT in functions since it calls again and again so JUST use it in main function to call ONCE.
     * ! ATTENTION: To use parallel programming (multi-processes) it needs to call srand per each process.
     */
    srand(time(NULL));

    system("cls || clear");

    showServices();

    serviceSelected = getService();

    setService(serviceSelected);

    return 0;
}

void showServices() {
    char servicesName[SERVICES_LEN][10] = {"TSP", "Knapsack", "N-Queens", "Exit"};

    puts("Hello\nThis program is created by \"Yasin Gourkani\"\tStudent ID:\"9974359\"\nShiraz University\n");
    puts("E-Mail: yassingourkani@outlook.com\n");
    puts("(ATTENTION) The program is running on multi-processes mode.\n");
    puts("Application Menu: \n");

    for (int i = 0; i < SERVICES_LEN; i++)
        printf("\t%d- %s\n", i + 1, servicesName[i]);
}

int getService() {
    int serviceNum = 0;

    printf("\nEnter the number of service in order to run: ");

    while (serviceNum < 1 || serviceNum > SERVICES_LEN) {

        // get the service number
        scanf("%d", &serviceNum);

        // show warning text to enter valid service number
        if (serviceNum < 1 || serviceNum > SERVICES_LEN)
            puts("\nEnter valid service number, Please!");
    }

    puts("");

    return serviceNum;
}

void setService(int serviceNum) {
    switch (serviceNum) {
        case 1:
            tspMain();
            break;
        case 2:
            knapsackMain();
            break;
        case 3:
            queensMain();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid service!\n\n");
    }
}