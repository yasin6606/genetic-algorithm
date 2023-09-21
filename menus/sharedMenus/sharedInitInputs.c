#include "../../includes/sharedLib.h"
#include "../../includes/sharedMenu.h"
#include "../../includes/types/generalTypes.h"

SharedMenuType sharedInitInputs() {
    SharedMenuType temp;

    temp.chromosomeLen = intInput("Enter the chromosome length: ");
    temp.populationLen = intInput("Enter the population length: ");
    temp.iteration = intInput("Enter the iteration count: ");
    temp.crossoverType = crossoverMenu();

    return temp;
}