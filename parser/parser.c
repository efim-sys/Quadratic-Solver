#include "parser.h"
#include <stdlib.h>
#include <ctype.h>

#include "../tools/tools.h"
#include "../unit-test/unit-test.h"

void removeChar(char str[], char c) {
	int to = 0;

	for (size_t from = 0; str[from] != '\0'; from ++) {
		if(str[from] != c) str[to++] = str[from]; 
	}

	str[to] = '\0';
}

bool isDigitPart(char symbol) {
	return symbol == '+' || symbol == '-' || isdigit(symbol) ;
}

void skipFromNumber(const char str[], int* shift) {
	(*shift) ++;
	while (str[*shift] != '-' && str[*shift] != '+' && str[*shift] != '=' && str[*shift] != '\0') (*shift) ++;
}

void skipToNumber(const char str[], int* shift) {
	while (!isDigitPart(str[*shift]) && str[*shift] != '\0') {
		// printf("*shift = %d   s[*shift] = %c\n", *shift, s[*shift]);
		(*shift) ++;
	}
}

void replaceChar(char str[], const char from, const char to) {
	for (size_t i = 0; str[i] != '\0'; i++) {
		str[i] = (str[i] == from) ? to : str[i]; 
	}
}

void parsePolynomial(const char str[], struct Coeffs* coeffs, int sign) {
	char *s = (char*) malloc(strlen(str) + 1); // TODO: strdup			// Allocate memory for string copy
	
	strcpy(s, str);
	removeChar(s, ' ');									// Remove all spaces, multiply signs, power signs
	removeChar(s, '*');
	removeChar(s, '^');
	replaceChar(s, 'X', 'x');							// Convert all X to lower case
	replaceChar(s, 'x', 'p');
	
	double tmp = 0;										// Temporary storage for readed coefficient

	for(int shift = 0; s[shift] != '\0';) {
		tmp = strtod(s + shift, NULL);							// Read value
		skipFromNumber(s, &shift);						// Move current symbol from the first number

		if (shift > 1 && s[shift - 2] == 'p' && s[shift - 1] == '2') {	// If coefficient for x^2 (x2) was found
			if(dEqual(tmp, 0) && (shift == 2 || s[shift - 3] != '0')) {		// If coefficient is not specified as number (e.g. -x^2 or x^2)
				
				if(shift > 2 && s[shift - 3] == '-') tmp = -1;
				else								 tmp = 1;
			}

			coeffs->a += tmp * sign;
		}


		else if	(shift > 0 && s[shift - 1] == 'p')	{					// If coefficient for x was found
			if(dEqual(tmp, 0) && (shift == 1 || s[shift - 2] != '0')) {
				if(shift > 1 && s[shift - 2] == '-') tmp = -1;
				else								 tmp = 1;
			}

			coeffs->b += tmp * sign;
		}

		else coeffs->c += tmp * sign;

		skipToNumber(s, &shift);
	}

	free(s);
}

void parseEquation(const char str[], struct Coeffs* coeffs) {
	size_t str_len 	= strlen(str);
	size_t eq_index 	= (size_t) strchr(str, '=');

	char* left_side = NULL;
	char* right_side = NULL;
	
	bool has_right = true;

	if(eq_index == 0) {
		eq_index = str_len;
		has_right = false;
	}
	else {
		eq_index = eq_index - (size_t) str;
	}

	left_side	= (char*) calloc(eq_index+1, sizeof(char));
	memcpy(left_side, str, eq_index);

	left_side[eq_index] 	= '\0';
	parsePolynomial(left_side, coeffs, 1);
	free(left_side);

	if(has_right) {
		right_side	= (char*) calloc(str_len - eq_index, sizeof(char));
		memcpy(right_side, str + eq_index + 1, str_len - eq_index - 1);

		right_side[str_len - eq_index-1] 	= '\0';
		parsePolynomial(right_side, coeffs, -1);
		free(right_side);
	}
}
