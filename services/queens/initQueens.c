#include "../../headers/mainHeaders.h"

// get the number of queens to initiate the problem
int getQueensInitValues();

// set matrix for queens (arrays of solutions)
int *setQueensSol(int nQueens);

int getQueensInitValues() {
    int n;

    // get the number of products (n)
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    return n;
}

int *setQueensSol(int nQueens) {
    int *queensArr = (int *) calloc(nQueens * nQueens, sizeof(int));
    int *row;

    for (int i = 0; i < nQueens; i++) {
        row = makePerm(nQueens);

        for (int j = 0; j < nQueens; j++) {
            queensArr[i * nQueens + j] = row[j];
        }
    }

    printMatrix(nQueens, queensArr);

    return queensArr;
}