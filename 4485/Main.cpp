#include<stdio.h>
#include<queue>
#include<memory.h>

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a; y = b;
	}
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
std::queue <pos> q;

int main() {
	int t = 0;
	while (1) {
		t++;
		int n;
		scanf("%d", &n);
		if (n == 0)return 0;
		int map[150][150] = { 0 };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		int ans[150][150];
		memset(ans, 60, sizeof(ans));
		ans[1][1] = map[1][1];
		q.push(pos(1, 1));
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx<1 || nx>n || ny<1 || ny>n)continue;
				if (ans[nx][ny] > ans[x][y] + map[nx][ny]) {
					ans[nx][ny] = ans[x][y] + map[nx][ny];
					q.push(pos(nx, ny));
				}
			}
		}
		printf("Problem %d: %d\n",t, ans[n][n]);
	}
	return 0;
}