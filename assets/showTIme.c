#include "../includes/sharedLib.h"

void showTime(size_t seconds) {
    size_t hr, min, sec;

    hr = seconds / 3600;

    min = (seconds - (hr * 3600)) / 60;

    sec = (seconds - (hr * 3600)) - (min * 60);

    printf("\nSolving Time: %.2zu:%.2zu:%.2zu\n", hr, min, sec);
}