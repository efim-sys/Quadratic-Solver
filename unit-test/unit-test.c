#include <stdbool.h>
#include "unit-test.h"
#include "../tools/tools.h"
#include "../solver/solver.h"
#include "../parser/parser.h"
// #include "../termColors.h"

#include "test-arrays.h"

void utestParseEquation(void) {
	printf("Test ParseEquation()\n");

	const size_t num_tests = sizeof(arr_utest_equation) / sizeof(arr_utest_equation[0]);

	for(unsigned int i = 0; i < num_tests; i++) {
		struct UTestParse test = arr_utest_equation[i];

		double a = 0, b = 0, c = 0;
		parseEquation(test.str, &a, &b, &c);

		if(!(dEqual(a, test.exp.a) && dEqual(b, test.exp.b) && dEqual(c, test.exp.c))) {
			printf("\033[91mERROR\033[39m");
			printf("\t[%s] Expected: [A=%lg B=%lg C=%lg] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c, a, b, c);
		}
		else {
			if(show_fine) {
				printf("\033[92mFINE\033[39m");
				printf("\t[%s] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c);
			}
		}

	}
}

void utestSolveSq(void) {
	printf("Test SolveSquare()\n");

	const size_t num_tests = sizeof(arr_utest_solve) / sizeof(arr_utest_solve[0]);

	for(unsigned int i = 0; i < num_tests; i++) {
		struct UTestSolve test = arr_utest_solve[i];

		double a = 0, b = 0, c = 0;
		parseEquation(test.str, &a, &b, &c);

		double x1 = 0, x2 = 0;
		enum SolveResult nRoots = solveSq(a, b, c, &x1, &x2);
		
		if(!(nRoots == test.exp.nRoots && dEqual(x1, test.exp.x1) && dEqual(x2, test.exp.x2))) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [n=%d x1=%+lg x2=%+lg] Got: [n=%d x1=%+lg x2=%+lg]\n", test.str, test.exp.nRoots, test.exp.x1, test.exp.x2, 
				nRoots, x1, x2);
		}
		else {
			if(show_fine) printf("\033[92mFINE\033[39m\t[%s] Got: [n=%d x1=%+lg x2=%+lg]\n", test.str, nRoots, x1, x2);
		}
	}
}

void utestParsePolynomial(void) {
	printf("Test ParsePolynomial()\n");

	const size_t num_tests = sizeof(arr_utest_poly) / sizeof(arr_utest_poly[0]);

	for(unsigned int i = 0; i < num_tests; i++) {
		struct UTestParse test = arr_utest_poly[i];

		double a = 0, b = 0, c = 0;
		parsePolynomial(test.str, &a, &b, &c, 1);

		if(!(dEqual(a, test.exp.a) && dEqual(b, test.exp.b) && dEqual(c, test.exp.c))) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [A=%lg B=%lg C=%lg] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c, a, b, c);
		}
		else {
			if(show_fine) printf("\033[92mFINE\033[39m\t[%s] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c);
		}

	}
}