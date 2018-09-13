#include<stdio.h>

int gcd(int a, int b) {
	return !(a%b) ? b : gcd(b, a%b);
}

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int mo = b*d;
	int ja = a*d + b*c;
	printf("%d %d\n", ja / gcd(ja, mo), mo / gcd(ja, mo));
	return 0;
}