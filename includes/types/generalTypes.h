//
// Created by yasin on 6/11/23.
//

#ifndef GENETIC_ALGORITHM_GENERALTYPES_H
#define GENETIC_ALGORITHM_GENERALTYPES_H

typedef struct {
    int chromosomeLen;
    int populationLen;
    int iteration;
    int crossoverType;
} SharedMenuType;

typedef struct {
    int idx;
    int value;
} EvalType;

#endif //GENETIC_ALGORITHM_GENERALTYPES_H
