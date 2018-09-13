#include<stdio.h>
#include<queue>
#include<memory.h>

struct pos {
	int x;
	int y;
	pos() {};
	pos(int a, int b) {
		x = a;
		y = b;
	}
};

int dx[8] = { 0,0,1,-1,-1,-1,1,1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
std::queue <pos> q;
bool chkmap[55][55] = { 0 };
int map[55][55] = { 0 };

int main() {
	while (1) {
		int n, m;
		memset(chkmap, 0, sizeof(chkmap));
		memset(map, 0, sizeof(map));
		scanf("%d %d", &m, &n);
		if (n == 0 && m == 0)return 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &map[i][j]);
			}
		}
/*		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}*/
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == true && chkmap[i][j] == false) {
					q.push(pos(i, j));
					chkmap[i][j] = true;
					cnt++;
					while (!q.empty()) {
						int x = q.front().x;
						int y = q.front().y;
						q.pop();
						for (int k = 0; k < 8; k++) {
							if (chkmap[x + dx[k]][y + dy[k]] == true)continue;
							if (map[x + dx[k]][y + dy[k]] == 0)continue;
							chkmap[x + dx[k]][y + dy[k]] = true;
							q.push(pos(x + dx[k], y + dy[k]));
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}