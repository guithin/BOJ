#include<stdio.h>
#include<memory.h>
#include<algorithm>

struct pos {
	int idx, time;
	pos() {};
	pos(int a, int b) {
		time = a;
		idx = b;
	}
	bool operator<(const pos&io)const {
		return time < io.time;
	}
};

int n, m, q;
pos g[510];
int map[510][510] = { 0 };
int sub[510][510] = { 0 };

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		g[i] = pos(temp, i);
		sub[i][i] = temp;
	}
	memset(map, 40, sizeof(map));
	for (int i = 1; i <= n; i++)map[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (map[a][b] > c) {
			map[a][b] = c;
			map[b][a] = c;
			sub[a][b] = sub[b][a] = std::max(g[a].time, g[b].time);
		}
	}
	std::sort(g + 1, g + 1 + n);
	for (int k = 1; k <= n; k++) {
		int temp = g[k].idx;
		int temp2 = g[k].time;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int nmax = std::max({ sub[i][j], temp2, sub[i][temp], sub[temp][j] });
				if (map[i][j] + sub[i][j] > map[i][temp] + map[temp][j] + nmax) {
					sub[i][j] = nmax;
					map[i][j] = map[i][temp] + map[temp][j];
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", map[a][b] + sub[a][b] < map[0][0] ? map[a][b] + sub[a][b] : -1);
	}
	return 0;
}