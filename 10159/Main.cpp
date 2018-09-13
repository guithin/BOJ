#include<stdio.h>

int n, m;
int map[110][110] = { 0 };

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = -1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!map[i][j] && map[i][k] == 1 && map[k][j] == 1)map[i][j] = 1;
				if (!map[i][j] && map[i][k] == -1 && map[k][j] == -1)map[i][j] = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!map[i][j])cnt++;
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}