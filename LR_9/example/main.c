#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Circle {
	int rX, rY;
	int R;
};

struct Ring {
	struct Circle inner, outher;
};


struct Point {
	int i, j;
};

bool isPointInCircle(const struct Point *p, const struct Circle * c) {
	int dx = p->j - c->rX;
	int dy = p->i - c->rY;
	return dx * dx + dy*dy <= c->R * c->R;
}

bool isPointInRing(const struct Ring *r, const struct Point *p) {
	return !isPointInCircle(p, &r->inner) && isPointInCircle(p, &r->outher);
}

int mod(int a, int b) {
	return (a % b + b) % b;
}

int max(int a, int b) {
	return (a < b ? b : a);
}
int min(int a, int b) {
	return (a > b ? b : a);
}

int sign(int a) {
	return (a >= 0 ? 1 : -1);
}



int main() {
	struct Ring r = {{5, 10, 5}, {5, 10, 10}};
	struct Point p = {18, -9};
	int l = 5;

	int k = 0;
	while(k < 50 && !isPointInRing(&r, &p)) {
		printf("k = %d, i = %d, j = %d\n", k, p.i, p.j);
		struct Point p0 = p;
		p.i = mod(p0.i*max(p0.j, l), 30) + mod(p0.j * min(p0.i, l), 20) + k;
		p.j = min(p0.i, max(p0.j, min(l, max(p0.i - l, p0.j - l))));
		l = sign(k-10)*abs(p0.i - p0.j + l - k);

		k = k + 1;
	}
	
	if(isPointInRing(&r, &p)) {
		printf("Point in ring: k = %d, i = %d, j = %d\n", k, p.i, p.j);
	} else {
		printf("Point not in ring: k = %d, i = %d, j = %d\n", k, p.i, p.j);
	}

		

	return 0;
}
