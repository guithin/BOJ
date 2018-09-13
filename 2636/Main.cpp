#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>
using namespace std;

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a; y = b;
	}
};

int n, m;
int map[110][110];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main() {
	memset(map, 0xff, sizeof(map));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int cnt = 0;
	int ans = 0;
	while (++cnt) {
		queue<pos>q;
		int ddd = 1;

		for (int i = 0; i <= m + 1; i++) {
			q.push(pos(0, i));
			q.push(pos(n + 1, i));
		}
		for (int i = 0; i <= n + 1; i++) {
			q.push(pos(i, 0));
			q.push(pos(i, m + 1));
		}
		bool vst[110][110] = {};
		int era[110][110] = {};
		bool flag = false;
		while (q.size()) {
			pos now = q.front(); q.pop();
			for (int d = 0; d < 4; d++) {
				int nx = now.x + dx[d];
				int ny = now.y + dy[d];
				if (nx<0 || nx>n + 1)continue;
				if (ny<0 || ny>m + 1)continue;
				if (vst[nx][ny])continue;
				vst[nx][ny] = true;
				if (map[nx][ny] < 1) {
					q.push(pos(nx, ny));
				}
				else {
					era[nx][ny] = true;
					flag = true;
				}
			}
		}
		if (!flag) {
			printf("%d\n%d\n", cnt - 1, ans);
			return 0;
		}
		else {
			ans = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (map[i][j])ans++;
					if (era[i][j])map[i][j] = 0;
				}
			}
		}

	}
	return 0;
}