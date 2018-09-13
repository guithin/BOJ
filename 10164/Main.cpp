#include<stdio.h>

int n, m, k;
int pas[110][110];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	pas[0][0] = 1;
	for (int i = 1; i <= n + m; i++) {
		for (int j = 0; j <= i; j++) {
			pas[i][j] += pas[i - 1][j - 1] + pas[i - 1][j];
		}
	}
	int x = (k - 1) / m + 1;
	int y = (k - 1) % m + 1;
	if (!k) {
		x = 1; y = 1;
	}
	printf("%d\n", pas[x + y - 2][x - 1] * pas[n - x + m - y][n - x]);
	return 0;
}