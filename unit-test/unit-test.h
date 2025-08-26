const bool showFine = true;

void utestParseEquation(void);
void utestParsePolynomial(void);
void utestSolveSq(void);

struct peqStruct {
	const char *str;

	double a, b, c;
};

struct TestCase {
	const char* equation;
	double expected_a;
	double expected_b;
	double expected_c;
	int expected_roots;
	double expected_root1;
	double expected_root2;
};