#include "parser.h"
#include <stdlib.h>
#include "../tools/tools.h"

void removeChar(char str[], char c) {
	int j = 0;

	for(int i = 0; str[i] != '\0'; i++) {
		if(str[i] != c) str[j++] = str[i]; 
	}

	str[j] = '\0';
}

bool isDigitPart(char c) {
	return c == '+' || c == '-' || (c >= '0' && c <= '9') ;
}

void skipFromNumber(const char s[], int* shift) {
	(*shift) ++;
	while(s[*shift] != '-' && s[*shift] != '+' && s[*shift] != '=' && s[*shift] != '\0') (*shift) ++;
}

void skipToNumber(const char s[], int* shift) {
	while(!isDigitPart(s[*shift]) && s[*shift] != '\0') {
		// printf("*shift = %d   s[*shift] = %c\n", *shift, s[*shift]);
		(*shift) ++;
	}
}

void replaceChar(char str[], const char from, const char to) {
	for(int i = 0; str[i] != '\0'; i++) {
		str[i] = (str[i] == from) ? to : str[i]; 
	}
}

void parsePolynomial(const char str[], double *a, double* b, double* c, int sign) {
	char *s = (char*) malloc(strlen(str) + 1);			// Allocate memory for string copy

	strcpy(s, str);
	removeChar(s, ' ');									// Remove all spaces, multiply signs, power signs
	removeChar(s, '*');
	removeChar(s, '^');
	replaceChar(s, 'X', 'x');							// Convert all X to lower case
	replaceChar(s, 'x', 'p');
	
	double tmp = 0;										// Temporary storage for readed coefficient

	for(int shift = 0; s[shift] != '\0';) {
		tmp = atof(s+shift);							// Read value
		skipFromNumber(s, &shift);						// Move current symbol from the first number

		if (shift > 1 && s[shift-2] == 'p' && s[shift-1] == '2') {	// If coefficient for x^2 (x2) was found
			if(dEqual(tmp, 0) && (shift == 2 || s[shift-3] != '0')) {		// If coefficient is not specified as number (e.g. -x^2 or x^2)
				// printf("ttt=%lg\n", atof("0P2+"));
				
				if(shift > 2 && s[shift-3] == '-') 	tmp = -1;
				else								tmp = 1;
			}
			*a += tmp * sign;
		}


		else if	(shift > 0 && s[shift-1] == 'p')	{					// If coefficient for x was found
			if(dEqual(tmp, 0) && (shift == 1 || s[shift-2] != '0')) {
				if(shift > 1 && s[shift-2] == '-') 	tmp = -1;
				else								tmp = 1;
			}
			*b += tmp * sign;
		}

		else *c += tmp * sign;

		skipToNumber(s, &shift);
	}
	free(s);
}

void parseEquation(const char str[], double *a, double *b, double *c) {
	*a = 0; *b = 0; *c = 0;

	size_t strLen 	= strlen(str);
	size_t eqIndex 	= (size_t) strchr(str, '=');

	char* left_side, *right_side;
	
	bool has_right = true;

	if(eqIndex == 0) {
		eqIndex = strLen;
		has_right = false;
	}
	else {
		eqIndex = eqIndex - (size_t) str;
	}

	left_side	= (char*) malloc(eqIndex+1);
	memcpy(left_side, str, eqIndex);
	left_side	[eqIndex] 	= '\0';
	parsePolynomial(left_side, a, b, c, 1);
	free(left_side);

	if(has_right) {
		right_side	= (char*) malloc(strLen - eqIndex);
		memcpy(right_side, str+eqIndex+1, strLen-eqIndex-1);
		right_side[strLen - eqIndex-1] 	= '\0';
		parsePolynomial(right_side, a, b, c, -1);
		free(right_side);
	}
}
