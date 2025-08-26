enum SolveResult {
    NO_ROOTS = 0,
    ONE_ROOT, 
    TWO_ROOTS,
    INF_ROOTS
};

//! @brief Solves an quadratic equation from given koefficients
//! @param double a
//! @param double b
//! @param double c
//! @param double *x1 pointer to first root variable
//! @param double *x2 pointer to second root variable
//! @returns enum SolveResult NO_ROOTS, ONE_ROOT, TWO_ROOTS, INF_ROOTS
enum SolveResult solveSq(double a, double b, double c, double *x1, double *x2);