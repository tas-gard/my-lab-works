#include "../include/matrix.h"
#include "stdio.h"
#include "stdbool.h"

int main() {
    int w, h;
    scanf("%d %d", &w, &h);

    Matrix m = Matrix_create(w, h, 0);
    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            scanf("%d", Matrix_at(&m, i, j));

    printf("Matrix before \n");
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            printf("%d ", *Matrix_at(&m, i, j));
        }
        printf("\n");
    }

    Matrix_swap_sum_cols(&m);

    printf("Matrix after \n");
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            printf("%d ", *Matrix_at(&m, i, j));
        }
        printf("\n");
    }

    Matrix_destroy(&m);
    return 0;
}
