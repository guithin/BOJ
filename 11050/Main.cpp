#include<stdio.h>

int main() {
		int a, b, c = 1;
		long long R=1;
		scanf("%d %d", &a, &b);
		for (int i = a-b+1; i <= a; i++) {
			if (R%c == 0) {
				R /= c;
				c++;
			}
			R *= i;

		}
		for (int i = c; i <= b; i++) {
			R /= i;
		}
		printf("%lld\n", R);
	return 0;
}