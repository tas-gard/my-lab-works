#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "operations.h"


int main(void) {
    power_arr();
    int n;
    scanf("%d", &n);

    int nLen = len(n);
    bool found = false;


    for (int i = 0; i + 2 < nLen; ++i) {
        int i_0 = nLen - 1 - i;
        int i_1 = nLen - 1 - (i + 1);
        int i_2 = nLen - 1 - (i + 2);

        int a = ind(n, i_0);
        int b = ind(n, i_1);
        int c = ind(n, i_2);

        if (a < b && b < c) {
            printf("%d%d%d\n", a, b, c);
            found = true;
        }
    }

    if (!found) 
        printf("троект нет\n");

    return 0;
}