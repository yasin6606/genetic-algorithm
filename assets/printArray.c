#include "../headers/sharedLib.h"
#include "../headers/sharedMacros.h"

void printArray(size_t size, const int *arr, char *text, char *color) {
    puts("");
    printf("%s%s", color, text);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("%s\n\n%s", ANSI_COLOR_RESET, ANSI_COLOR_RESET);
}