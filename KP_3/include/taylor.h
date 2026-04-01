#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef double (*NthElement)(double, double, size_t);

double taylor(NthElement ntnElemFunc, double x, double precision, size_t maxIterations, size_t *nIteration);