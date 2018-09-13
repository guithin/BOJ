#include<stdio.h>
#include<memory.h>
#include<queue>

struct pos {
	int x, y, z;
	pos() {};
	pos(int a, int b, int c) {
		x = a; y = b; z = c;
	}
};

std::queue <pos> q;
char map[33][33][33] = { 0 };
int mapp[33][33][33] = { 0 };
bool chk[33][33][33] = { 0 };
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

int main() {
	while (1) {
		memset(mapp, 60, sizeof(mapp));
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));
		int n, m, h;
		pos temp;
		pos fin;
		scanf("%d %d %d", &h, &n, &m);
		if (h == 0 && n == 0 && m == 0)return 0;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("\n");
				for (int k = 1; k <= m; k++) {
					scanf("%c", &map[i][j][k]);
					if (map[i][j][k] == 'S') {
						temp = pos(i, j, k);
						mapp[i][j][k] = 0;
					}
					if (map[i][j][k] == 'E') {
						fin = pos(i, j, k);
					}
				}
			}
		}
		q.push(temp);
		bool flag = false;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				if (map[x + dx[i]][y + dy[i]][z + dz[i]] != '.'&& map[x + dx[i]][y + dy[i]][z + dz[i]] != 'E')continue;
				if (chk[x + dx[i]][y + dy[i]][z + dz[i]])continue;
				if (mapp[x + dx[i]][y + dy[i]][z + dz[i]] > mapp[x][y][z] + 1) {
					mapp[x + dx[i]][y + dy[i]][z + dz[i]] = mapp[x][y][z] + 1;
				}
				chk[x + dx[i]][y + dy[i]][z + dz[i]] = true;
				q.push(pos(x + dx[i], y + dy[i], z + dz[i]));
			}
		}
		if (mapp[fin.x][fin.y][fin.z] < mapp[0][0][0]) {
			printf("Escaped in %d minute(s).\n", mapp[fin.x][fin.y][fin.z]);
		}
		else printf("Trapped!\n");
	}
	return 0;
}