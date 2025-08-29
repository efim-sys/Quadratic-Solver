#pragma once

#include "../solver/solver.h"

const bool show_fine = true;

void utestParseEquation(void);
void utestParsePolynomial(void);
void utestSolveSq(void);

struct Coeffs {
	double a, b, c;
};

struct UTestParse {
	const char *str;
	struct Coeffs exp;
};

struct UTestSolve {
	const char* str;
	struct Coeffs coeffs;
	struct Solution exp;
};