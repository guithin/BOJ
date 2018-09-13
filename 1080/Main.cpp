#include<stdio.h>

int A[55][55] = { 0 };
int B[55][55] = { 0 };
int n, m;
int ans = 0;

void print() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", A[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

void change(int x, int y) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (A[x + i][y + j] == 1)A[x + i][y + j] = 0;
			else A[x + i][y + j] = 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &A[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &B[i][j]);
		}
	}
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 2; j++) {
			if (A[i][j] != B[i][j]) { 
				ans++;
				change(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] != B[i][j]) {
				printf("%d\n", -1);
				return 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}