//
// Created by yasin on 5/31/23.
//

#ifndef GENETIC_ALGORITHM_SHAREDMACROS_H
#define GENETIC_ALGORITHM_SHAREDMACROS_H

#define SERVICES_LEN 4
#define K_COMPETITION 3
#define PARENTS_NUM 2
#define CROSSOVER_TYPE_LEN 2
#define ELITE_PERCENT 0.04
#define MUTATION_PERCENT 0.3
#define MORE_SAME_RESULT_NUM 3
#define SPRINTF_STRING_LEN 50

// Const numbers
#define ONE_LEN 1
#define TWO_LEN 2
#define THREE_LEN 3

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
#define DASHED_LINE puts("\n---------------------------------------------------------------------");

// Debugger
#define SHOW_NUM(X) printf("\n%d \n", X);
#define SLEEP_TESTER(X) printf("Start\n"); sleep(X); printf("End\n");

// Errors
#define SHOW_ERROR(TEXT) printf("%s(Error)%s %s\n\n", ANSI_COLOR_RED, TEXT, ANSI_COLOR_RESET);
#define SHOW_WARNING(TEXT) printf("\n\n%s(Wrong) %s %s\n\n", FONT_COL_CUSTOM(255,204,0), TEXT, ANSI_COLOR_RESET);

#endif //GENETIC_ALGORITHM_SHAREDMACROS_H
