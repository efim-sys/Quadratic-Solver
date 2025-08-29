#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "tools.h"

bool dEqual(double a, double b) {
    const double prescicion = __DBL_EPSILON__;
    return fabs(a - b) < prescicion;
}

void filecopy(FILE* from, FILE* to) {
    int c = 0;

    while((c = getc(from)) != EOF) putc(c, to);
}

bool coeffsComp(const struct Coeffs* c1 , const struct Coeffs* c2){
    return dEqual(c1->a, c2->a) && dEqual(c1->b, c2->b) && dEqual(c1->c, c2->c);
}

bool solutionComp(const struct Solution* s1 , const struct Solution* s2){
    return s1->nRoots == s2->nRoots && dEqual(s1->x1, s2->x1) && dEqual(s1->x2, s2->x2);
}

bool objCmp(const void* a, const void* b, const size_t size) {
    
    const char* ptra = (const char*) a;
    const char* ptrb = (const char*) b;
    
    // printf("OBJCOMP() start %c [%d] size = %d\n", *ptra, *ptra, size);
    
    for(size_t i = 0; i < size; i++) {
        
        if(ptra[i] != ptrb[i]) return false;
    }
    
    return true;
}