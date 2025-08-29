#pragma once

#include "../complex/complex.h" // TODO: -I complex/.

enum SolveResult {
    NO_ROOTS = 0,
    ONE_ROOT, 
    TWO_ROOTS,
    INF_ROOTS,
    COMPL_ROOTS = 9
};

struct Solution {
	enum SolveResult nRoots;
	double x1, x2;
};

#include "../unit-test/unit-test.h"

//! @brief Solves an quadratic equation from given koefficients
//! @param struct Coeffs
//! @param struct Solution*
//! @returns enum SolveResult NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS
enum SolveResult solveSq(struct Coeffs coeffs, struct Solution* solution);

double calcDiscr(struct Coeffs coeffs);
enum SolveResult solveComplex(struct Coeffs coeffs, Complex* r1, Complex* r2);