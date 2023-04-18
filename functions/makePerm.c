#include "../headers/mainHeaders.h"
#include "time.h"

int x = 0;

int *makePerm(int n) {
    srand(x);
    x += 2;

    int num, j;
    int *arr = (int *) calloc(n * n, sizeof(int));

    for (int i = 0; i < n; i++) {
        do {
            num = rand() % n;

            // check if the number is already in the arr
            for (j = 0; j < n; j++)
                if (arr[j] == num)
                    break;
        } while (j < i);

        arr[i] = num;
    }

    return arr;
}
