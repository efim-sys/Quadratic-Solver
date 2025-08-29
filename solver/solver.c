#include "stdlib.h"
#include "assert.h"
#include "../tools/tools.h"
#include "../complex/complex.h"
#include "../unit-test/unit-test.h"
#include <math.h>

#include "solver.h"

enum SolveResult solveSq(struct Coeffs coeffs, struct Solution* solution) { // struct 
    assert(solution != NULL);
    
    if(dEqual(coeffs.a, 0)) {                                      // Если уравнение не является квадратным
        if(dEqual(coeffs.b, 0)) {                                  // Если уравнение задает прямую
            solution->nRoots = dEqual(coeffs.c, 0) ? INF_ROOTS : NO_ROOTS;
            return solution->nRoots;                               // Если прямая совпадает с Ox, то INF_ROOTS, иначе NO_ROOTS
        }

        solution->x1 = -coeffs.c / coeffs.b;                                       // Решение линейного уравнения
        solution->nRoots = ONE_ROOT;
        return solution->nRoots;
    }

    double D = calcDiscr(coeffs);

    solution->nRoots = NO_ROOTS;
    
    if(D > 0) {
        solution->nRoots = TWO_ROOTS;
    }
    else if(dEqual(D, 0)) {
        solution->nRoots = ONE_ROOT;
    }
    else {
        solution->nRoots = NO_ROOTS;
        return solution->nRoots;            // Уравнение не имеет действительных корней
    }

    double sqD = sqrt(D);

    solution->x1 = (-coeffs.b + sqD) / (2 * coeffs.a);
    solution->x2 = (-coeffs.b - sqD) / (2 * coeffs.a);

	if(solution->x1 < solution->x2) {
		double tmp = solution->x1;
		solution->x1 = solution->x2;
		solution->x2 = tmp;
	}

    return solution->nRoots;
}


enum SolveResult solveComplex(struct Coeffs coeffs, Complex* r1, Complex* r2) {
    if(dEqual(coeffs.a, 0)) {                                      // Если уравнение не является квадратным
        if(dEqual(coeffs.b, 0)) {                                  // Если уравнение задает прямую
            return dEqual(coeffs.c, 0) ? INF_ROOTS : NO_ROOTS;     // Если прямая совпадает с Ox, то INF_ROOTS, иначе NO_ROOTS
        }
        r1->real = -coeffs.c / coeffs.b;                                     // Решение линейного уравнения
        return ONE_ROOT;
    }

    double D = calcDiscr(coeffs);
    Complex sqD = sqrtComplex(D);

    *r1 = divComplex(addReal(sqD, -coeffs.b), 2 * coeffs.a);
    *r2 = divComplex(addReal(mulComplex(sqD, -1), -coeffs.b), 2 * coeffs.a);
    
    if(dEqual(D, 0)) return ONE_ROOT;
    if(D > 0) return TWO_ROOTS;

    return COMPL_ROOTS;
    
}

double calcDiscr(struct Coeffs coeffs) {
    return coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
}

