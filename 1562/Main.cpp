#include<stdio.h>

const int mod = 1000000000;
int n;
int map[110][10][2050] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i < 10; i++) {
		map[1][i][1 << i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j != 9) {
					map[i + 1][j + 1][k | (1 << (j + 1))] += map[i][j][k];
					map[i + 1][j + 1][k | (1 << (j + 1))] %= mod;
				}
				if (j) {
					map[i + 1][j - 1][k | (1 << (j - 1))] += map[i][j][k];
					map[i + 1][j - 1][k | (1 << (j - 1))] %= mod;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += map[n][i][1023];
		ans %= mod;
	}
	printf("%d\n", ans);
	return 0;
}