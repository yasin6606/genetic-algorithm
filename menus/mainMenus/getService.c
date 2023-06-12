#include "../../headers/sharedLib.h"

int getService() {
    int serviceNum = 0;

    printf("\nEnter the number of service in order to run: ");
    fflush(stdout);

    while (serviceNum < 1 || serviceNum > SERVICES_LEN) {

        // get the service number
        scanf("%d", &serviceNum);

        // show warning text to enter valid service number
        if (serviceNum < 1 || serviceNum > SERVICES_LEN)
            puts("\nEnter valid service number, Please!");
        fflush(stdout);
    }

    puts("");

    return serviceNum;
}
