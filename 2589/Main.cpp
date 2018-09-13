#include<stdio.h>
#include<queue>
#include<memory.h>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
char map[55][55] = {};
int chk[55][55] = {};
int l, w;
queue<int>qx;
queue<int>qy;

int qstart(int x, int y) {
	memset(chk, 40, sizeof(chk));
	chk[x][y] = 0;
	qx.push(x); qy.push(y);
	while (qx.size()) {
		int nx = qx.front(); qx.pop();
		int ny = qy.front(); qy.pop();
		for (int d = 0; d < 4; d++) {
			if (map[nx + dx[d]][ny + dy[d]] == 'L'&&chk[nx + dx[d]][ny + dy[d]] > chk[nx][ny] + 1) {
				chk[nx + dx[d]][ny + dy[d]] = chk[nx][ny] + 1;
				qx.push(nx + dx[d]);
				qy.push(ny + dy[d]);
			}
		}
	}
	int maxi = 0;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			if (chk[i][j]<10000 && chk[i][j]>maxi)
				maxi = chk[i][j];
		}
	}
	return maxi;
}

int main() {
	memset(map, 'W', sizeof(map));
	scanf("%d %d", &l, &w);
	for (int i = 1; i <= l; i++) {
		scanf("%s", map[i] + 1);
	}
	int ans = 0;
	for (int i = 1; i <= l; i++) {
		for (int j = 1; j <= w; j++) {
			if (map[i][j] == 'L') {
				int tmp = qstart(i, j);
				if (ans < tmp)
					ans = tmp;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}