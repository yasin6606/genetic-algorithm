#include "./initKnapsack.c"

void knapsackMain() {
    struct knapsackInitValues init;

    init = getKnapsackInitValues();

    setKnapsackSol(init);
}