#include<stdio.h>
int n;

int sqr(int x, int y) {
	int r = 1;
	for (int i = 1; i <= y; i++) {
		r *= x;
	}
	return r;
}

void hano(int x, int y, int num) {
	if (num == 1) {
		printf("%d %d\n", x, y);
		return;
	}
	if (x == 1) {
		if (y == 3) {
			hano(1, 2, num - 1);
			printf("%d %d\n", x, y);
			hano(2, 3, num - 1);
		}
		else if (y == 2) {
			hano(1, 3, num - 1);
			printf("%d %d\n", x, y);
			hano(3, 2, num - 1);
		}
	}
	else if (x == 2) {
		if (y == 1) {
			hano(2, 3, num - 1);
			printf("%d %d\n", x, y);
			hano(3, 1, num - 1);
		}
		else if (y == 3) {
			hano(2, 1, num - 1);
			printf("%d %d\n", x, y);
			hano(1, 3, num - 1);
		}
	}
	else if (x == 3) {
		if (y == 1) {
			hano(3, 2, num - 1);
			printf("%d %d\n", x, y);
			hano(2, 1, num - 1);
		}
		else if (y == 2) {
			hano(3, 1, num - 1);
			printf("%d %d\n", x, y);
			hano(1, 2, num - 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	printf("%d\n", sqr(2, n) - 1);
	hano(1, 3, n);
	return 0;
}