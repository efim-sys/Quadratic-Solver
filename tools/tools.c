#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "tools.h"

bool dEqual(double a, double b) {
    const double prescicion = __DBL_EPSILON__;
    return fabs(a - b) < prescicion;
}

void filecopy(FILE* from, FILE* to) {
    int c = 0;

    while((c = getc(from)) != EOF) putc(c, to);
}