#include<stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (b < c || d < a) {
		printf("%d\n", b - a + d - c);
		return 0;
	}
	if (a <= c && d <= b) {
		printf("%d\n", b - a);
		return 0;
	}
	if (c <= a && b <= d) {
		printf("%d\n", d - c);
		return 0;
	}
	printf("%d\n", d - a > b - c ? d - a : b - c);
	return 0;
}