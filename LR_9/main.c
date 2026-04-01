#include <math.h>
#include <stdbool.h>
#include <stdio.h>

struct Point {
  int i, j;
};

struct Circle {
  struct Point center;
  int r;
};

struct Ring {
  struct Circle inner, outer;
};

bool isPointInCircle(const struct Point *p, const struct Circle *circle) {
  int dx = p->i - circle->center.i;
  int dy = p->j - circle->center.j;

  int distance2 = dx * dx + dy * dy;
  return distance2 < circle->r * circle->r;
}

bool isPointInRing(const struct Point *p, const struct Ring *ring) {
  return isPointInCircle(p, &ring->outer) && !isPointInCircle(p, &ring->inner);
}

int mod(int a, int b) { return (a % b + b) % b; }

int min(int a, int b) { return (a < b ? a : b); }

int max(int a, int b) { return (a > b ? a : b); }

int sign(int a) { return (a < 0 ? -1 : 1); }

int abs(int a) { return (a < 0 ? -a : a); }

int main(int argc, char *argw[]) {
  // начальные условия: i = 1, j = -30, l = 1
  int l = 1;
  struct Point p = {1, -30};


  struct Ring ring = {.inner = {.center = {10, 10}, .r = 5},
                      .outer = {.center = {10, 10}, .r = 10}};
  int maxIterations = 50;
	printf("Input max iterations: ");
	scanf("%d", &maxIterations);
  int k = 0;
  while (k < maxIterations) {
    printf("k = %d, i = %d, j = %d\n", k, p.i, p.j);
    if (isPointInRing(&p, &ring))
      break;
    struct Point newP;
    newP.i = max(min(p.i + p.j - l - k, p.i - p.j + l - k), min(k + p.i - p.j - l, k - p.i - p.j + l));
    newP.j = p.j + mod(l * sign(p.j), 20) + mod(k * sign(p.i), 10);
    l = abs(p.i - p.j + l - k) * sign(p.i) * sign(p.j);
    p = newP; 
    ++k;
  }

  if (isPointInRing(&p, &ring))
    printf("Point in ring; k = %d, i = %d, j = %d\n", k, p.i, p.j);
  else
    printf("Point NOT in ring k = %d, i = %d, j = %d\n", k, p.i, p.j);

  return 0;
}