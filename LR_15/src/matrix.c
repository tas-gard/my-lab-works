#include "../include/matrix.h"
#include "assert.h"
#include "stdlib.h"

Matrix Matrix_create(int w, int h, int defaultElement) {
    Matrix res = {NULL, w, h};
    res.data = malloc(w * h * sizeof(int));
    for(int i = 0; i < w*h; ++i)
        res.data[i] = defaultElement;
    
    return res;
}

Matrix Matrix_copy(const Matrix *other) {
    Matrix res = Matrix_create(other->w, other->h, 0);
    for(int i = 0; i < res.h; ++i)
        for(int j = 0; j < res.w; ++j)
            *Matrix_at(&res, i, j) = *Matrix_at(other, i, j);

    return res;
}

void Matrix_destroy(Matrix *m) {
    free(m->data);
    m->data = NULL;
}

void Matrix_swap_cols(Matrix *m, int c1, int c2) {
    if (c1 == c2) return;

    for(int i = 0; i < m->h; ++i) {
        int *a = Matrix_at(m, i, c1);
        int *b = Matrix_at(m, i, c2);
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void Matrix_swap_sum_cols(Matrix *m) {
    int w = m->w, h = m->h;

    // Сумма 0-го столбца — стартовая
    long long sum0 = 0;
    for(int i = 0; i < h; ++i)
        sum0 += *Matrix_at(m, i, 0);

    int jMin = 0, jMax = 0;
    long long minSum = sum0, maxSum = sum0;

    // Остальные столбцы
    for (int j = 1; j < w; ++j) {
        long long s = 0;
        for (int i = 0; i < h; ++i)
            s += *Matrix_at(m, i, j);

        if (s < minSum) {        // строго меньше => при равенстве сохраняется минимальный номер
            minSum = s;
            jMin = j;
        }

        if (s > maxSum) {        // строго больше => при равенстве сохраняется минимальный номер
            maxSum = s;
            jMax = j;
        }
    }

    Matrix_swap_cols(m, jMin, jMax);
}

int *Matrix_at(const Matrix *m, int i, int j) {
    assert(i >= 0 && i < m->h);
    assert(j >= 0 && j < m->w);

    return &m->data[i*m->w + j];
}