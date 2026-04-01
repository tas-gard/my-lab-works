#include "../include/operations.h"
#include <stdio.h>
#include <assert.h>

long long power[10];

int abs(int n) {
    return (n >= 0 ? n : -n);
}

int len(int n) {
    n = abs(n);
    if (n == 0)
        return 1;

    int count = 0;
    while (n > 0) {
        ++count;
        n /= 10;
    }
    return count;
}

int ind(int n, int index) {
    assert(index < 10);
    n = abs(n);
    return (n / power[index]) % 10;
}

void power_arr(void) {
    long long p = 1;
    for (size_t i = 0; i < 10; ++i) {
        power[i] = p;
        p *= 10;   
    }
}