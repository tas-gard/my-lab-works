#include "taylor.h"
#include <math.h>

double taylor(NthElement ntnElemFunc, double x, double precision, size_t maxIterations, size_t *nIteration){
    double result = 0;
    double nPrev = 0;

    for(size_t n = 1; n < maxIterations; ++n) {
        double term = ntnElemFunc(x, nPrev, n);
        nPrev = term;
        result += term;
        if (nIteration)
            *nIteration = n;
        if (fabs(term) < precision)
            break;
    }
    return result;
}
