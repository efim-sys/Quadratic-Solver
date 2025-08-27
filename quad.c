#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include "parser/parser.h"
#include "complex/complex.h"
#include "solver/solver.h"
#include "unit-test/unit-test.h"
#include "tools/tools.h"

#define myAssert(b) if(b) {printf("Assertion: File {%s} Line %d\n", __FILE__, __LINE__);abort();}

const int ARR_LEN = 128;

void outputResult(enum SolveResult nRoots, double x1, double x2);
void outputResultComplex(enum SolveResult nRoots, Complex r1, Complex r2);


const int nFlags = 4;

enum FLAGS {
    HELP_MODE = 0,
    TEST_MODE,
    COEF_MODE,
    COMPL_MODE
};

bool getFlag(enum FLAGS);
void setFlag(const char* str);


int main(int argc, const char* argv[]) {
    for(int i = 1; i < argc; i++) {
        setFlag(argv[i]);
    }

    if(getFlag(HELP_MODE)) {
        FILE *fp = fopen("helpfile.txt", "r");

        assert(fp!=NULL);

        filecopy(fp, stdout);

        fclose(fp);
        exit(0);
    }

    if(getFlag(TEST_MODE)) {
        utestParsePolynomial();
        utestParseEquation();
        utestSolveSq();
    }
    double a = 0, b = 0, c = 0;
    if(getFlag(COMPL_MODE)) printf("Работатет в режиме комплексных чисел\n");
    if(!getFlag(COEF_MODE)) {
        printf("\033[95mВведите квадратное или линейное уравнение:\033[39m\n");
    
        char str[ARR_LEN];
        fgets(str, ARR_LEN, stdin);

        parseEquation(str, &a, &b, &c);
    }
    else {
        printf("\033[95mВведите коэффициенты квадратного уравнения a b c:\033[39m\n");
        scanf("%lg %lg %lg", &a, &b, &c);
    }


    if(!getFlag(COMPL_MODE)) {
        double x1 = 0, x2 = 0;

        enum SolveResult nRoots = solveSq(a, b, c, &x1, &x2);
        outputResult(nRoots, x1, x2);
    }
    else {
        Complex r1, r2;

        enum SolveResult nRoots = solveComplex(a,b,c, &r1, &r2);
        outputResultComplex(nRoots, r1, r2);
    }
    
    return 0;
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
        case COMPL_ROOTS:
        default:
            printf("Error nRoots=%d x1=%+lg x2=%+lg\033[39m\n", nRoots, x1, x2);
            break;
    }
}

unsigned int flags = 0;

const char *flags_str[nFlags] = {
    "--help",
    "--test",
    "--coef",
    "--compl"
};

void setFlag(const char* str) {
    for(int i = 0; i < nFlags; i++) {
        if(!strcmp(str, flags_str[i])) flags |= (1u << i);
    }
}

bool getFlag(enum FLAGS f) {
    return flags & (1 << f);
}

void outputResultComplex(enum SolveResult nRoots, Complex r1, Complex r2) {
    printf("\033[93m"); // Orange
    switch(nRoots) {
        case NO_ROOTS:
            printf("Уравнение не имеет корней\033[39m\n");
            break;
        case ONE_ROOT:
            printf("Уравнение имеет 1 корень:\033[39m %+lg\n", r1.r);
            break;
        case TWO_ROOTS:
            printf("Уравнение имеет 2 корня:\033[39m %+lg %+lg\n", r1.r, r2.r);
            break;
        case INF_ROOTS:
            printf("Уравнение имеет ∞ корней\033[39m\n"); 
            break;
        case COMPL_ROOTS:
            printf("Уравнение имеет 2 комплексных корня:\033[39m\n");
            printComplex(r1);
            printComplex(r2);
            break;
        default:
            printf("Error nRoots=%d\033[39m\n", nRoots);
            break;
    }
}

