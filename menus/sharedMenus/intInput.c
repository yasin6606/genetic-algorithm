#include "../../headers/sharedLib.h"
#include "../../headers/sharedMacros.h"

int intInput(char *text) {
    int temp;

    printf("%s%s", text, ANSI_COLOR_CYAN);
    fflush(stdout);
    scanf("%d", &temp);
    printf("%s", ANSI_COLOR_RESET);
    fflush(stdout);

    return temp;
}