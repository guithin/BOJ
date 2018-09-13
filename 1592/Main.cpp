#include<stdio.h>

int gcd(int a, int b) {
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}
	return !(a%b) ? b : gcd(b, a%b);
}


int main() {
	int n, m, l;
	scanf("%d %d %d", &n, &m, &l);
	printf("%d\n", n/gcd(n, l)*(m - 1));
	return 0;
}