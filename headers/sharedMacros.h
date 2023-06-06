//
// Created by yasin on 5/31/23.
//

#ifndef GENETIC_ALGORITHM_SHAREDMACROS_H
#define GENETIC_ALGORITHM_SHAREDMACROS_H

#define SERVICES_LEN 4
#define K 3
#define PARENTS_NUM 2
#define CROSSOVER_TYPE_LEN 2

#define N_TIMES(X, Y) (X * Y)

// String colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define FONT_COL_CUSTOM(R, G, B)   "\e[38;2;" #R ";" #G ";" #B "m"
#define BG_COL_CUSTOM(R, G, B)   "\e[48;2;" #G ";" #G ";" #B "m"

#define GO_FIRST_OF_CURRENT_LINE "\r"
#define RM_CURRENT_LINE "\33[2K\r"

// Lines
#define DASHED_LINE puts("\n---------------------------------------------------------------------")

// Debugger
#define SHOW_NUM(X) printf("\n%d \n", X);

#endif //GENETIC_ALGORITHM_SHAREDMACROS_H
