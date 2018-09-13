#include<stdio.h>
#include<vector>
#include<memory.h>

struct start {
	struct pos {
		int s, e, c;
		pos() {};
		pos(int a, int b, int c) {
			s = a;
			e = b;
			this->c = c;
		}
	};

	int n, m, w;
	int map[510][510];

	int main() {
		scanf("%d %d %d", &n, &m, &w);
		memset(map, 40, sizeof(map));
		for (int i = 1; i <= n; i++)map[i][i] = 0;
		for (int i = 1; i <= m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (map[a][b] > c)map[a][b] = c;
			if (map[b][a] > c)map[b][a] = c;
		}
		for (int i = 1; i <= w; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (map[a][b] > -c)map[a][b] = -c;
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (map[i][j] > map[i][k] + map[k][j])map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (map[i][i] < 0) {
				printf("YES\n");
				return 0;
			}
		}
		printf("NO\n");
		return 0;
	}
	start() {};

};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		start temp;
		temp.main();
	}
	return 0;
}