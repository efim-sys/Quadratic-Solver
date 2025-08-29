#include <stdbool.h>
#include "unit-test.h"
#include "../tools/tools.h"
#include "../solver/solver.h"
#include "../parser/parser.h"
#include "../unit-test/unit-test.h"
// #include "../termColors.h"

#include "test-arrays.h"

void utestParseEquation(void) {
	printf("Test ParseEquation()\n");

	const size_t num_tests = sizeof(arr_utest_equation) / sizeof(arr_utest_equation[0]);

	for(unsigned int i = 0; i < num_tests; i++) {
		struct UTestParse test = arr_utest_equation[i];

		struct Coeffs coeffs = {};
		
		parseEquation(test.str, &coeffs);

		if(!coeffsComp(&coeffs, &test.exp)) {
			printf("\033[91mERROR\033[39m");
			printf("\t[%s] Expected: [A=%lg B=%lg C=%lg] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c, coeffs.a, coeffs.b, coeffs.c);
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

		struct Coeffs coeffs = {};
		parseEquation(test.str, &coeffs);

		struct Solution solution = {};
		solveSq(coeffs, &solution);
		
		if(!solutionComp(&solution, &test.exp)) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [n=%d x1=%+lg x2=%+lg] Got: [n=%d x1=%+lg x2=%+lg]\n", test.str, test.exp.nRoots, test.exp.x1, test.exp.x2, 
				solution.nRoots, solution.x1, solution.x2);
		}
		else {
			if(show_fine) printf("\033[92mFINE\033[39m\t[%s] Got: [n=%d x1=%+lg x2=%+lg]\n", test.str, solution.nRoots, solution.x1, solution.x2);
		}
	}
}

void utestParsePolynomial(void) {
	printf("Test ParsePolynomial()\n");

	const size_t num_tests = sizeof(arr_utest_poly) / sizeof(arr_utest_poly[0]);

	for(unsigned int i = 0; i < num_tests; i++) {
		struct UTestParse test = arr_utest_poly[i];

		struct Coeffs coeffs = {};
		parsePolynomial(test.str, &coeffs, 1);

		if(!coeffsComp(&coeffs, &test.exp)) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [A=%lg B=%lg C=%lg] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c, coeffs.a, coeffs.b, coeffs.c);
		}
		else {
			if(show_fine) printf("\033[92mFINE\033[39m\t[%s] Got: [A=%lg B=%lg C=%lg]\n", test.str, test.exp.a, test.exp.b, test.exp.c);
		}

	}
}