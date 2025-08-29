#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! @brief Removes given character c from the string
//! @param char str[] - input and output string
//! @param char c - character to be removed
void removeChar(char str[], char c);

//! @brief Parses quadratic equation coefficeents from the string
//! @param char str[] - input string
//! @param double *a
//! @param double *b
//! @param double *c
void parseEquation(const char str[], struct Coeffs*);

//! @brief Parses quadratic (or lower power) polynomial coefficeents from the string
//! @param char str[] - input string
//! @param double *a
//! @param double *b
//! @param double *c
//! @param int sign +1 or -1
void parsePolynomial(const char str[], struct Coeffs*, int sign);


void skipToNumber(const char s[], int* shift); 
bool isDigitPart(char c);
void skipFromNumber(const char s[], int* shift);
void replaceChar(char str[], const char from, const char to);
