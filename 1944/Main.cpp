#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
struct xy {
	int x, y;
	xy(){}
	xy(int a, int b) {
		x = a; y = b;
	}
};
struct pos {
	int from, to, cost;
	pos() {};
	pos(int a, int b, int c) {
		from = a;
		to = b;
		cost = c;
	}
	bool operator<(const pos&io)const {
		return cost < io.cost;
	}
};
int n, m;
int map[55][55] = { 0 };
xy start;
std::vector<xy>key;
std::priority_queue<pos>costq;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int table[300] = { 0 };
int find(int x) {
	if (table[x] == x)return x;
	return table[x] = find(table[x]);
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m + 1; i++)table[i] = i;
	for (int i = 1; i <= n; i++) {
		scanf(" ");
		for (int j = 1; j <= n; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S') {
				start = xy(i, j);
				key.push_back(start);
				map[i][j] = '0';
			}
			if (map[i][j] == 'K') {
				key.push_back(xy(i, j));
				map[i][j] = '0';
			}
		}
	}
	for (int i = 0; i <= m; i++) {
		xy from = key[i];
		int tmap[55][55];
		bool check[55][55] = { 0 };
		memcpy(tmap, map, sizeof(map));
		tmap[from.x][from.y] = 0;
		std::queue<xy>q;
		q.push(from);
		while (!q.empty()) {
			xy now = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				if (tmap[now.x + dx[j]][now.y + dy[j]] != '0')continue;
				tmap[now.x + dx[j]][now.y + dy[j]] = tmap[now.x][now.y] + 1;
				check[now.x + dx[j]][now.y + dy[j]] = true;
				q.push(xy(now.x + dx[j], now.y + dy[j]));
			}
		}
		for (int j = i + 1; j <= m; j++) {
			if(check[key[j].x][key[j].y])
				costq.push(pos(i + 1, j + 1, -tmap[key[j].x][key[j].y]));
		}
	}
	int cnt = 0;
	int ans = 0;
/*	while (!costq.empty()) {
		pos now = costq.top();
		costq.pop();
		printf("%d %d %d\n", now.from, now.to, -now.cost);
	}*/
	while (!costq.empty()) {
		pos now = costq.top();
		costq.pop();
		if (find(now.from) != find(now.to)) {
			table[find(now.from)] = find(now.to);
			ans += -now.cost;
			cnt++;
		}
		if (cnt == m)break;
	}
	int c = find(1);
	for (int i = 1; i <= m + 1; i++) {
		if (find(i) != c) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}