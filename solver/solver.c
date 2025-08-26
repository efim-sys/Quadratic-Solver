#include "solver.h"
#include "stdlib.h"
#include "assert.h"
#include "../tools/tools.h"
#include <math.h>

enum SolveResult solveSq(double a, double b, double c, double *x1, double *x2) {
    assert(x1 != NULL);
    assert(x2 != NULL);
    
    if(dEqual(a, 0)) {                                      // Если уравнение не является квадратным
        if(dEqual(b, 0)) {                                  // Если уравнение задает прямую
            return dEqual(c, 0) ? INF_ROOTS : NO_ROOTS;     // Если прямая совпадает с Ox, то INF_ROOTS, иначе NO_ROOTS
        }
        *x1 = -c / b;                                       // Решение линейного уравнения
        return ONE_ROOT;
    }

    double D = b*b - 4*a*c; // тогда уже везде пробелы
    // printf("[solveSq]\t\tD = %lg\n", D);

    enum SolveResult nRoots = NO_ROOTS;
    
    if(D > 0) {
        nRoots = TWO_ROOTS;
    }
    else if(dEqual(D, 0)) {
        nRoots = ONE_ROOT;
    }
    else {
        return NO_ROOTS; // Уравнение не имеет действительных корней
    }

    double sqD = sqrt(D);

    *x1 = (-b + sqD) / (2*a);
    *x2 = (-b - sqD) / (2*a);

	if(*x1 < *x2) {
		double tmp = *x1;
		*x1 = *x2;
		*x2 = tmp;
	}

    return nRoots;
}