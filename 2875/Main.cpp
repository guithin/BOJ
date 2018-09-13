#include<stdio.h>

int main() {
	int n, m, k;
	scanf("%d %d %d", &m, &n, &k);
	while(k--) {
		if (m >= 2 * n) {
//			printf("m\n");
			m--;
		}
		else {
//			printf("n\n");
			n--;
		}
	}
	if (m < 2 * n)
		printf("%d\n", m / 2);
	else
		printf("%d\n", n);
	return 0;
}