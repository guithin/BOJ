#include<stdio.h>

int n;
int map[2010][2010];
int inp[2010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", inp + i);
	for (int i = 1; i <= n; i++) {
		map[i][i] = 1;
	}

	for (int i = 1; i < n; i++) {
		if (inp[i] == inp[i + 1]) {
			map[i][i + 1] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (i + j > n)break;
			if (inp[i - j] == inp[i + j]) {
				map[i - j][i + j] += map[i - j + 1][i + j - 1];
			}
			if (i + j + 1 > n)continue;
			if (inp[i - j] == inp[i + j + 1]) {
				map[i - j][i + j + 1] += map[i - j + 1][i + j];
			}
		}
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", map[a][b] ? 1 : 0);
	}
	return 0;
}