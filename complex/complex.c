#include "complex.h"
#include "../tools/tools.h"
#include <math.h>

Complex sqrtComplex(double n)
{   
    Complex ret = {0, 0};
    if(n >= 0) ret.r = sqrt(n);
    else ret.i = sqrt(n);
}

void printComplex(const Complex c) {
    if(dEqual(c.i, 0)) printf("%lg", c.r);
    else printf(printf("{R=%lg i=%lg}", c.r, c.i));
}

Complex addComplex(const Complex a, const Complex b) {
    Complex ret = {a.r+b.r, a.i+b.i};
    return ret;
}

Complex mulComplex(const Complex a, const double b) {
    Complex ret = {a.r*b, a.i*b};

    return ret;
}