#include<stdio.h>

const int INF = 987654321;

int n;
int map[30][30] = { 0 };
int ans[30][30] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			ans[i][j] = map[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (k == i)continue;
			for (int j = 1; j <= n; j++) {
				if (j == i || j == k)continue;
				if (map[i][j] == map[i][k] + map[k][j]) {
					ans[i][j] = 0;
				}
				if (map[i][j] > map[i][k] + map[k][j]) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			sum += ans[i][j];
		}
	}
	printf("%d\n", sum);
	return 0;
}