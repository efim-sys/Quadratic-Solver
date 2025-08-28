#pragma once

typedef struct  {
    double real, imaginary;
} Complex;

void printComplex(Complex);
Complex addComplex(Complex a, Complex b);
Complex mulComplex(Complex a, double b);
Complex divComplex(Complex a, double b);
Complex sqrtComplex(double);
Complex addReal(Complex a, double b);