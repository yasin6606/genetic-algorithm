#include "../../headers/sharedLib.h"

// get the number of queens to initiate the problem
int getQueensInitValues();

// set matrix for queens (arrays of solutions)
int *setQueensSol(size_t nQueens);

int getQueensInitValues() {
    int n;

    // get the number of products (n)
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    return n;
}

int *setQueensSol(size_t nQueens) {
    int *queensArr = (int *) calloc(nQueens * nQueens, sizeof(int)), *permArr = makePerm(nQueens), i = 0, j = 0;

    while (i < nQueens) {
        if (j == nQueens) {

            // ! ! ! Per each row creation, start making new permutation array ! ! !
            permArr = makePerm(nQueens);

            i++;
            j = 0;
        }

        // add each element to each sol
        queensArr[i * nQueens + j] = permArr[j];

        j++;
    }

    return queensArr;
}

//// O(n^2) Old method
//int *setQueensSol(size_t nQueens) {
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