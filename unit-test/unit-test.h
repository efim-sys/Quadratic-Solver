#pragma once

const bool show_fine = true;

void utestParseEquation(void);
void utestParsePolynomial(void);
void utestSolveSq(void);

struct Coeffs {
	double a, b, c;
};

struct Solution {
	int nRoots;
	double x1, x2;
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