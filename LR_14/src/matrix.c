#include "../include/matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Matrix Matrix_create(int w, int h, int defaultElement) {
	Matrix result = {NULL, w, h};
	result.data = malloc(w*h*sizeof(int));
	for(int i = 0; i < w*h; ++i) 
		result.data[i] = defaultElement;

	return result;
}
Matrix Matrix_copy(const Matrix *other) {
	Matrix result = Matrix_create(other->w, other->h, 0);
	for(int i = 0; i < result.h; ++i) 
		for(int j = 0; j < result.w; ++j) 
			*Matrix_at(&result, i, j) = *Matrix_at(other, i, j);

	return result;
}

void Matrix_destroy(Matrix *m) {
	free(m->data);
	m->data = NULL;
}

int * Matrix_at(const Matrix *m, int i, int j) {
	assert((i >= 0 && i < m->h));
	assert((j >= 0 && j < m->w));

	return &m->data[i*m->w + j];
}