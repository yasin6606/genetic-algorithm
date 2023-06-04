//
// Created by yasin on 5/31/23.
//

#ifndef GENETIC_ALGORITHM_SHAREDMACROS_H
#define GENETIC_ALGORITHM_SHAREDMACROS_H

#define SERVICES_LEN 4
#define K 3
#define PARENTS_NUM 2
#define CROSSOVER_TYPE_LEN 2

// String colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//#define FONT_COL_CUSTOM (R,G,B)   ("\e[38;2;" " " R " " ";" + G + ";" + B + "m")
#define BCKGRD_COL_CUSTOM_RED   "\e[48;2;200;0;0m"
#define BCKGRD_COL_CUSTOM_GREEN "\e[48;2;0;200;0m"
#define BCKGRD_COL_CUSTOM_BLUE  "\e[48;2;0;0;200m"

#define GO_FIRST_OF_CURRENT_LINE "\r"
#define RM_CURRENT_LINE "\33[2K\r"

#endif //GENETIC_ALGORITHM_SHAREDMACROS_H
