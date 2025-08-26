#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "parser/parser.h"
#include "solver/solver.h"
#include "unit-test/unit-test.h"

const int ARR_LEN = 128;

void outputResult(enum SolveResult nRoots, double x1, double x2);

void filecopy(FILE* from, FILE* to);

int main(int argc, const char* argv[]) {
    bool help_mode = 0, test_mode = 0, coef_mode = 0;

    for(int i = 1; i < argc; i++) {
        if(0 == strcmp(argv[i], "--help")) {
            help_mode = 1;
        }
        if(0 == strcmp(argv[1], "--test")) {
            test_mode = 1;
        }
        if(0 == strcmp(argv[1], "--coef")) {
            coef_mode = 1;
        }
    }
    // printf("help_mode=%d test_mode=%d\n", help_mode, test_mode);
    if(help_mode) {
        FILE *fp = fopen("helpfile.txt", "r");

        assert(fp!=NULL);

        filecopy(fp, stdout);

        fclose(fp);
        exit(0);
    }

    if(test_mode) {
        utestParsePolynomial();
        utestParseEquation();
        utestSolveSq();
    }

    double a = 0, b = 0, c = 0;
    if(!coef_mode) {
        printf("\033[95mВведите квадратное или линейное уравнение:\033[39m\n");
    
        char str[ARR_LEN];

        fgets(str, ARR_LEN, stdin);

        parseEquation(str, &a, &b, &c);
    }
    else {
        printf("\033[95mВведите коэффициенты квадратного уравнения a b c:\033[39m\n");

        scanf("%lg %lg %lg", &a, &b, &c);
    }

    double x1 = 0, x2 = 0;

    enum SolveResult nRoots = solveSq(a, b, c, &x1, &x2);
    
    outputResult(nRoots, x1, x2);
    
    return 0;
}

void filecopy(FILE* from, FILE* to) {
    int c;

    while((c=getc(from)) != EOF) putc(c, to);
}

void outputResult(enum SolveResult nRoots, double x1, double x2) {
	printf("\033[93m"); // Orange
    switch(nRoots) {
        case NO_ROOTS:
            printf("Уравнение не имеет корней\033[39m\n");
            break;
        case ONE_ROOT:
            printf("Уравнение имеет 1 корень:\033[39m %+lg\n", x1);
            break;
        case TWO_ROOTS:
            printf("Уравнение имеет 2 корня:\033[39m %+lg %+lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Уравнение имеет ∞ корней\033[39m\n"); 
            break;
        default:
            printf("Error nRoots=%d x1=%+lg x2=%+lg\033[39m\n", nRoots, x1, x2);
            break;
    }
}

