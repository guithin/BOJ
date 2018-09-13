#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

struct pos {
	int x, y, d;
	pos() {};
	pos(int a, int b, int c) {
		x = a; y = b; d = c;
	}
};

int n, m;
int map[110][110] = {};
int cst[110][110][4] = {};
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, 1, -1, 0 };

int main() {
	memset(cst, 40, sizeof(cst));
	memset(map, 1, sizeof(map));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int fucking[10];
	for (int i = 1; i <= 6; i++)scanf("%d", fucking + i);
	fucking[3] %= 4; fucking[6] %= 4;
	cst[fucking[1]][fucking[2]][fucking[3]] = 0;
	queue<pos>q;
	q.push(pos(fucking[1], fucking[2], fucking[3]));
	while (q.size()) {
		pos now = q.front(); q.pop();
		if (cst[now.x][now.y][now.d % 3 ? 0 : 1] > cst[now.x][now.y][now.d] + 1) {
			cst[now.x][now.y][now.d % 3 ? 0 : 1] = cst[now.x][now.y][now.d] + 1;
			q.push(pos(now.x, now.y, now.d % 3 ? 0 : 1));
		}
		if (cst[now.x][now.y][now.d % 3 ? 3 : 2] > cst[now.x][now.y][now.d] + 1) {
			cst[now.x][now.y][now.d % 3 ? 3 : 2] = cst[now.x][now.y][now.d] + 1;
			q.push(pos(now.x, now.y, now.d % 3 ? 3 : 2));
		}
		for (int d = 1; d < 4; d++) {
			int nx = now.x + dx[now.d] * d;
			int ny = now.y + dy[now.d] * d;
			if (nx < 1 || ny < 1)continue;
			if (!map[nx][ny] && cst[nx][ny][now.d] > cst[now.x][now.y][now.d] + 1) {
				cst[nx][ny][now.d] = cst[now.x][now.y][now.d] + 1;
				q.push(pos(nx, ny, now.d));
			}
			else if (map[nx][ny])break;
		}
	}
	printf("%d\n", cst[fucking[4]][fucking[5]][fucking[6]]);
	return 0;
}