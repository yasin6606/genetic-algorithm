#include "../../headers/sharedLib.h"
#include "../../headers/sharedMacros.h"

int getService() {
    int serviceNum = 0;

    printf("\nEnter the number of service in order to run: %s", ANSI_COLOR_CYAN);
    fflush(stdout);

    while (serviceNum < 1 || serviceNum > SERVICES_LEN) {

        // get the service number
        scanf("%d", &serviceNum);

        // show warning text to enter valid service number
        if (serviceNum < 1 || serviceNum > SERVICES_LEN)
            printf("%sPlease, Enter valid service number: %s", ANSI_COLOR_RED, ANSI_COLOR_CYAN);
        fflush(stdout);
    }
    printf("%s", ANSI_COLOR_RESET);

    puts("");

    return serviceNum;
}
