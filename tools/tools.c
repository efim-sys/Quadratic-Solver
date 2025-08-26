
#include <stdbool.h>
#include <math.h>
#include "tools.h"

bool dEqual(double a, double b) {
    const double prescicion = __DBL_EPSILON__;
    return fabs(a - b) < prescicion;
}