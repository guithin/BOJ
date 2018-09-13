#include<stdio.h>

int main() {
		int n1 = 0, m1 = 0, n2 = 0, m2 = 0;
		int a[100][100] = { 0 };
		int b[100][100] = { 0 };
		int c[100][100] = { 0 };

		scanf("%d %d", &n1, &m1);
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m1; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		scanf("%d %d", &n2, &m2);
		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < m2; j++) {
				scanf("%d", &b[i][j]);
			}
		}
		if (n2 == m1) {
			for (int i = 0; i < n1; i++) {
				for (int j = 0; j < m2; j++) {
					for (int k = 0; k < n2; k++) {
						c[i][j] += a[i][k] * b[k][j];
					}
				}
			}
			for (int i = 0; i < n1; i++) {
				for (int j = 0; j < m2 - 1; j++) {
					printf("%d ", c[i][j]);
				}
				printf("%d\n", c[i][m2 - 1]);
			}
		}
		else
			printf("Impossible\n");
	return 0;
}