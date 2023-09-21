#include "../includes/sharedLib.h"
#include "../includes/sharedMacros.h"

void printArray(size_t size, const int *arr, char *text, char *color) {
    puts("");
    printf("%s%s", color, text);
    fflush(stdout);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n\n%s", ANSI_COLOR_RESET);
}