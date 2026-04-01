#include "../include/taylor.h"
#include <math.h>

double CalcEps(void) {
    double eps = 1.0;
    while ((1.0 + eps / 2.0) > 1.0) {
        eps /= 2.0;
    }
    return eps;
}

double var3(double x, double prev, size_t n) {
    if (n == 1) return x;
    double sn   = (n % 2 == 1) ? 1.0 : -1.0;
    double sn_1 = ((n - 1) % 2 == 1) ? 1.0 : -1.0;

    double p2n   = pow(2.0, (double)n);       
    double p2n_1 = pow(2.0, (double)(n - 1)); 

    double num_n   = sn   * p2n   - 1.0;
    double num_n_1 = sn_1 * p2n_1 - 1.0;

    double rat = x * (num_n * (double)(n - 1)) / (num_n_1 * (double)n);
    return prev * rat;
}

double var3Analytic(double x) { 
    return log(1.0 + x - 2.0 * x * x);
}

int main(void) {
    double eps = CalcEps();

    size_t k;
    printf("Input k: ");
    if (scanf("%zu", &k) != 1) return 0;

    double precision = eps * (double)k;
    double a = -0.2, b = 0.3;
    double dx = 0.05;
    size_t maxIter = 100;

    printf("x \ttaylor(x) \t\tanalytic(x) \t\titerations\n");

    for (double x = a; x <= b; x += dx) {
        size_t nIterations = 0;
        double t = taylor(var3, x, precision, maxIter, &nIterations);

        printf("%5.2f\t% .15f\t% .15f\t%zu\n", x, t, var3Analytic(x), nIterations);
    }

    return 0;
}