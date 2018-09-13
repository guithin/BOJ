#include<stdio.h>
#include<memory.h>

int n, m;
int map[300][300] = { 0 };

int main() {
	memset(map, 40, sizeof(map));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)map[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = 0;
		if (c)map[b][a] = 0;
		else map[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	int cur;
	scanf("%d", &cur);
	for (int i = 1; i <= cur; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", map[a][b]);
	}
	return 0;
}