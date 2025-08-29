#pragma once

typedef struct  {
    double real, imaginary;
} Complex;

void printComplex(const Complex*);
Complex addComplex(const Complex a, const Complex b);
Complex mulComplex(const Complex a, const double b);
Complex divComplex(const Complex a, const double b);
Complex sqrtComplex(const double);
Complex addReal(const Complex a, const double b);