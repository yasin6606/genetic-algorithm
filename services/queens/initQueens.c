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
    int *queensArr = (int *) calloc(nQueens * nQueens, sizeof(int)), i = 0, j = 0;

    while (i < nQueens) {
        if (j == nQueens) {
            i++;
            j = 0;
        }

        // add each element to each sol
        queensArr[i * nQueens + j] = makePerm(nQueens)[j];

        j++;
    }

    return queensArr;
}

//// O(n^2) Old method
//int *setQueensSol(int nQueens) {
//    int *queensArr = (int *) calloc(nQueens * nQueens, sizeof(int));
//    int *row = NULL;
//
//    for (int i = 0; i < nQueens; i++) {
//        row = makePerm(nQueens);
//
//        for (int j = 0; j < nQueens; j++)
//            queensArr[i * nQueens + j] = row[j];
//    }
//
//    return queensArr;
//}