#include "headers/sharedLib.h"
#include "headers/mainMenu.h"

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