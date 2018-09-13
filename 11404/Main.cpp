#include<stdio.h>

struct pos {
	int from;
	int to;
	int cost;
	pos() {};
	pos(int a, int b, int c) {
		from = a;
		to = b;
		cost = c;
	}
};

pos edge[100010];
int map[110][110] = { 0 };
int inf = 987654321;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)map[i][j] = 0;
			else map[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int c;
		scanf("%d", &c);
		if (map[a][b] > c)map[a][b] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] > map[j][i] + map[i][k])
					map[j][k] = map[j][i] + map[i][k];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == inf)printf("0 ");
			else printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}