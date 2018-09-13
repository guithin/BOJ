#include<stdio.h>

int gcd(int a, int b) {
	return !(a%b) ? b : gcd(b, a%b);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int c = b / a;
	int ans = 1;
	for (int i = 1; i*i < c; i++) {
		if (c%i == 0) {
			if (gcd(i, c / i) > 1)continue;
			ans = i;
		}
	}
	printf("%d %d\n", a*ans, a*c/ans);
	return 0;
}