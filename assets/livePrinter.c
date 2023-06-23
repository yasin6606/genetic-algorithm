#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void livePrinter(char *text, int start, char *textColor, char *digitColor, bool keepLine) {
    printf(RM_CURRENT_LINE);
    printf(GO_FIRST_OF_CURRENT_LINE);

    if (start == -1)
        printf("%s%s%s", textColor, text, ANSI_COLOR_RESET);
    else
        printf("%s%s%s: %s%d%s", textColor, text, ANSI_COLOR_RESET, digitColor, start, ANSI_COLOR_RESET);

    fflush(stdout);

    if (keepLine)
        puts("");
}