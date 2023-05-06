#include "./initQueens.c"

void queensMain() {
    int n, *queensMatrix = NULL, *e = NULL;

    n = getQueensInitValues();

    setQueensSol(n);
}