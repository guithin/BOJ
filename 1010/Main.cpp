#include<stdio.h>

int pas[33][33];

int main() {
	pas[0][0] = 1;
	for (int i = 1; i <= 30; i++) {
		pas[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			pas[i][j] = pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", pas[m][n]);
	}
	return 0;
}