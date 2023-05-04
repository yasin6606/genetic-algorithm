#include "../../headers/mainHeaders.h"
#include "../../functions/makePerm.c"

// get the number of cities to initiate the problem
int getTSPInitValues();

// set DIS matrix
int *setDisSol(int n);

int getTSPInitValues() {
    int citiesNum = 0;

    printf("Enter the number of cities: ");
    scanf("%d", &citiesNum);

    return citiesNum;
}

int *setDisSol(int n) {
    int *disArr = (int *) calloc(n * n, sizeof(int));
    int *randArr;

    for (int i = 0; i < n; i++) {
        randArr = makePerm(n);

        // make main diameter zero (moving non-zero elements on main diameter to zero element)
        for (int j = 0; j < n; j++) {
            if (randArr[i] == 0) continue;

            // randArr[i] == element on main diameter | randArr[j] == zero element
            if (randArr[j] == 0) {
                randArr[j] = randArr[i];
                randArr[i] = 0;
            }
        }

        // make DIS matrix
        for (int j = 0; j < n; j++) {
            disArr[i * n + j] = randArr[j];
        }
    }

    return disArr;
}