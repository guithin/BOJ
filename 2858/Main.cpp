#include<stdio.h>
#include<math.h>

int main() {
	int R, B;
	scanf("%d %d", &R, &B);
	int m = (R + 4 + (int)(sqrt((R + 4)*(R + 4) - (16 * (R + B))) + 1e-9)) / 4;
	int n = (R + 4) / 2 - m;
	if (m > n)printf("%d %d\n", m, n);
	else printf("%d %d\n", n, m);
	return 0;
}