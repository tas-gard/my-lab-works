#include "../include/matrix.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {  
  int w, h;
  scanf("%d %d", &h, &w);

  Matrix m = Matrix_create(w, h, 0);
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      scanf("%d", Matrix_at(&m, i, j));

  printf("Readed matrix: \n");
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      printf("%d ", *Matrix_at(&m, i, j));
		}
    printf("\n");
  }
printf("Linearized matrix: ");
/* Обход по диагоналям:
   s = i + j идёт от максимального (правый нижний угол)
   до 0 (левый верхний).
   Внутри диагонали идём снизу вверх: i уменьшается, j = s - i.
*/
for (int s = (h - 1) + (w - 1); s >= 0; --s) {
    // максимальная возможная строка на этой диагонали
    int i_start = (s < h) ? s : (h - 1);

    for (int i = i_start; i >= 0; --i) {
        int j = s - i;
        if (j < 0 || j >= w) {
            continue;   // вышли за пределы по столбцу
        }

        printf("%d ", *Matrix_at(&m, i, j));
    }
}

printf("\n");
  return 0;
}