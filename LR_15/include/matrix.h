struct Matrix {
    int *data;
    int w, h;
};

typedef struct Matrix Matrix;

Matrix Matrix_create(int w, int h, int defaultElement);
Matrix Matrix_copy(const Matrix *other);

void Matrix_destroy(Matrix *m);
void Matrix_swap_cols(Matrix *m, int c1, int c2);
void Matrix_swap_sum_cols(Matrix *m);
int *Matrix_at(const Matrix *m, int i, int j);