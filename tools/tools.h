#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "../unit-test/unit-test.h"
#include "../solver/solver.h"

//! @brief Compares 2 double variables and returns true if approximately equal
//! @param double a
//! @param double b
//! @returns bool equal
bool dEqual(double a, double b);

bool coeffsComp(const struct Coeffs* c1 , const struct Coeffs* c2);
bool solutionComp(const struct Solution* s1 , const struct Solution* s2);

void filecopy(FILE* from, FILE* to);

bool objCmp(const void* a, const void* b, const size_t size);
