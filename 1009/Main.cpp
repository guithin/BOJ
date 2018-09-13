#include<stdio.h>

int sqr(int a, int b) {
	int R = 1;
	for (int i = 1; i <= b; i++) {
		R *= a;
		if (R % 10 == 0) {
			R = 10;
			continue;
		}
		R %= 10;
	}
	return R;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		int sum = sqr(a, b);
		if (sum != 10)
			sum %= 10;
		printf("%d\n", sum);
	}
	return 0;
}