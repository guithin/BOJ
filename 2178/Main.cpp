#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

struct pos {
	int x, y, cost;
	pos(){}
	pos(int a, int b, int c) {
		x = a; y = b; cost = c;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

int n, m;
int map[110][110];
int srt[110][110];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
priority_queue<pos>q;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	memset(srt, 40, sizeof(srt));
	srt[1][1] = 0;
	q.push(pos(1, 1, 0));
	while (q.size()) {
		pos now = q.top(); q.pop();
		if (now.x == n && now.y == m)break;
		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (map[nx][ny] && srt[nx][ny] > srt[now.x][now.y] + 1) {
				srt[nx][ny] = srt[now.x][now.y] + 1;
				q.push(pos(nx, ny, srt[nx][ny]));
			}
		}
	}
	printf("%d\n", srt[n][m] + 1);
	return 0;
}