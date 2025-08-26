#include "complex.h"
#include "../tools/tools.h"
#include <math.h>
#include <stdio.h>

Complex sqrtComplex(double n)
{   
    Complex ret = {0, 0};
    if(n >= 0) ret.r = sqrt(n);
    else ret.i = sqrt(-n);

    return ret;
}

void printComplex(const Complex c) {
    if(dEqual(c.i, 0)) printf("%lg\n", c.r);
    else printf("{%+lg%+lg*i}\n", c.r, c.i);
}

Complex addComplex(const Complex a, const Complex b) {
    Complex ret = {a.r+b.r, a.i+b.i};
    return ret;
}

Complex mulComplex(const Complex a, const double b) {
    Complex ret = {a.r*b, a.i*b};

    return ret;
}

Complex addReal(const Complex a, const double b) {
    Complex ret = {a.r+b, a.i};
    return ret;
}

Complex divComplex(Complex a, double b) {
    Complex ret = {a.r/b, a.i/b};
    return ret;
}