#include "complex.h"
#include "../tools/tools.h"
#include <math.h>
#include <stdio.h>

Complex sqrtComplex(double n)
{   
    Complex ret = {0, 0};
    if (n >= 0) ret.real = sqrt(n);
    else ret.imaginary = sqrt(-n);

    return ret;
}

void printComplex(const Complex c) {
    if (dEqual(c.imaginary, 0)) printf("%lg\n", c.real);
    else printf("{%+lg%+lg*i}\n", c.real, c.imaginary);
}

Complex addComplex(const Complex a, const Complex b) {
    Complex ret = {a.real + b.real, a.imaginary + b.imaginary};
    return ret;
}

Complex mulComplex(const Complex a, const double b) {
    Complex ret = {a.real * b, a.imaginary * b}; 
    return ret;
}

Complex addReal(const Complex a, const double b) {
    Complex ret = {a.real + b, a.imaginary};
    return ret;
}

Complex divComplex(Complex a, double b) {
    Complex ret = {a.real / b, a.imaginary / b};
    return ret;
}