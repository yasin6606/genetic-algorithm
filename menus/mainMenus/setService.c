#include "../../includes/sharedLib.h"
#include "../../includes/services/tsp.h"
#include "../../includes/services/knapsack.h"
#include "../../includes/services/queens.h"

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
