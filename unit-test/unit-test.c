#include <stdbool.h>
#include "unit-test.h"
#include "../tools/tools.h"
#include "../solver/solver.h"
#include "../parser/parser.h"

#include "test-arrays.h"

void utestParseEquation(void) {
	printf("Test ParseEquation()\n");
	
	for(unsigned int i = 0; i < (sizeof(unitTests) / sizeof(struct peqStruct)); i++) {
		struct peqStruct e = unitTests[i];

		double a = 0, b = 0, c = 0;
		parseEquation(e.str, &a, &b, &c);

		if(!(dEqual(a, e.a) && dEqual(b, e.b) && dEqual(c, e.c))) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [A=%lg B=%lg C=%lg] Got: [A=%lg B=%lg C=%lg]\n", e.str, e.a, e.b, e.c, a, b, c);
		}
		else {
			if(showFine) printf("\033[92mFINE\033[39m\t[%s] Got: [A=%lg B=%lg C=%lg]\n", e.str, e.a, e.b, e.c);
		}

	}
}

void utestSolveSq(void) {
	printf("Test SolveSquare()\n");

	for(unsigned int i = 0; i < (sizeof(test_cases) / sizeof(struct TestCase)); i++) {
		struct TestCase e = test_cases[i];

		double a = 0, b = 0, c = 0;
		parseEquation(e.equation, &a, &b, &c);

		double x1 = 0, x2 = 0;
		enum SolveResult nRoots = solveSq(a, b, c, &x1, &x2);
		
		if(!(nRoots == e.expected_roots && dEqual(x1, e.expected_root1) && dEqual(x2, e.expected_root2))) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [n=%d x1=%+lg x2=%+lg] Got: [n=%d x1=%+lg x2=%+lg]\n", e.equation, e.expected_roots, e.expected_root1, e.expected_root2, 
				nRoots, x1, x2);
		}
		else {
			if(showFine) printf("\033[92mFINE\033[39m\t[%s] Got: [n=%d x1=%+lg x2=%+lg]\n", e.equation, nRoots, x1, x2);
		}
	}
}

void utestParsePolynomial(void) {
	printf("Test ParsePolynomial()\n");

	for(unsigned int i = 0; i < (sizeof(unitTests2) / sizeof(struct peqStruct)); i++) {
		struct peqStruct e = unitTests2[i];

		double a = 0, b = 0, c = 0;
		parsePolynomial(e.str, &a, &b, &c, 1);

		if(!(dEqual(a, e.a) && dEqual(b, e.b) && dEqual(c, e.c))) {
			printf("\033[91mERROR\033[39m\t[%s] Expected: [A=%lg B=%lg C=%lg] Got: [A=%lg B=%lg C=%lg]\n", e.str, e.a, e.b, e.c, a, b, c);
		}
		else {
			if(showFine) printf("\033[92mFINE\033[39m\t[%s] Got: [A=%lg B=%lg C=%lg]\n", e.str, e.a, e.b, e.c);
		}

	}
}