#include "../../headers/sharedLib.h"

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
