//
// Created by yasin on 6/4/23.
//

#ifndef GENETIC_ALGORITHM_SHAREDMENU_H
#define GENETIC_ALGORITHM_SHAREDMENU_H

#include "../menus/sharedMenus/crossoverMenu.c"
#include "../menus/sharedMenus/intInput.c"
#include "../menus/sharedMenus/sharedInitInputs.c"

size_t crossoverMenu();

int intInput(char *text);

SharedMenuType sharedInitInputs();

#endif //GENETIC_ALGORITHM_SHAREDMENU_H
