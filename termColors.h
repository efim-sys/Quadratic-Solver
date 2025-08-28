#pragma once

#include <stdio.h>

const char* colorCodes[] = {
    "39", "30", "31", "32", "33", "34", "35", "36", "37", "90", "91", "92", "93", "94", "95", "96", "97"
};

enum Colors {
    DEFAULT = 0,
    BLACK,
    DARKRED,
    DARKGREEN,
    DARKYELLOW,
    BARKBLUE,
    DARKPURPLE,
    DARKCYAN,
    LIGHTGRAY,
    DARKGRAY,
    RED,
    GREEN,
    ORANGE,
    BLUE,
    PURPLE,
    CYAN,
    WHITE
};

void setTermFG(enum Colors color);

void setTermFG(enum Colors color) {
    fputs("\033[", stdout);
    fputs(colorCodes[color], stdout);

    putchar('m');
}