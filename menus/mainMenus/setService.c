#include "../../headers/sharedLib.h"
#include "../../services/tsp/tspMain.c"
#include "../../services/knapsack/knapsackMain.c"
#include "../../services/queens/queensMain.c"

void setService(size_t serviceNum) {
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
