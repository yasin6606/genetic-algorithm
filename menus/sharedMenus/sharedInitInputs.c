#include "../../headers/sharedLib.h"
#include "../../headers/sharedMenu.h"
#include "../../types/generalTypes.h"

SharedMenuType sharedInitInputs() {
    SharedMenuType temp;

    temp.chromosomeLen = intInput("Enter the chromosome length: ");
    temp.populationLen = intInput("Enter the population length: ");
    temp.iteration = intInput("Enter the iteration count: ");
    temp.crossoverType = crossoverMenu();

    return temp;
}