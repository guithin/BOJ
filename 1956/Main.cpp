#include<stdio.h>
#include<memory.h>

int map[410][410] = { 0 };

int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	memset(map, 40, sizeof(map));
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (map[a][b] > c)map[a][b] = c;
	}
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (map[i][j] > map[i][k] + map[k][j])map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	int ans = map[0][0];
	for (int i = 1; i <= v; i++) {
		if (map[i][i] < ans)ans = map[i][i];
	}
	if (ans == map[0][0])printf("-1\n");
	else printf("%d\n", ans);
}