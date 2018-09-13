#include<stdio.h>

int main() {
	int w, h;
	int x, y;
	int t;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%d", &t);
	int dx = 1;
	int dy = 1;
	for (int i = 0; i < t; i++) {
		if (x + dx > w)dx = -1;
		if (x + dx < 0)dx = 1;
		if (y + dy > h)dy = -1;
		if (y + dy < 0)dy = 1;
		x += dx;
		y += dy;
	}
	printf("%d %d\n", x, y);
	return 0;
}