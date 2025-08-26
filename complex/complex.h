#ifndef COMPLEX_DEF
#define COMPLEX_DEF
typedef struct  {
    double r, i;
} Complex;

void printComplex(Complex);
Complex addComplex(Complex a, Complex b);
Complex mulComplex(Complex a, double b);
Complex divComplex(Complex a, double b);
Complex sqrtComplex(double);
Complex addReal(Complex a, double b);
#endif