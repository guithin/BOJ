#include<stdio.h>

int n, l;
int map[22][22];
int dp[4][22][22][22][22];
//dp[len][start_x][start_y][end_x][end_y]
int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[8] = { 1, -1, 0, 1, -1, 0, 1, -1 };

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			dp[1][i][j][i][j] = 1;
		}
	}
	if (!(l & 1)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int d = 0; d < 8; d++) {
					if (map[i][j] == map[i + dx[d]][j + dy[d]]) {
						dp[2][i][j][i + dx[d]][j + dy[d]]++;
					}
				}
			}
		}
	}
	for (int i = (l & 1) ? 1 : 2; i <= l - 2; i += 2) {
		for (int sx = 1; sx <= n; sx++) {//start_x
			for (int sy = 1; sy <= n; sy++) {//staty_y
				for (int ex = 1; ex <= n; ex++) {//end_x
					for (int ey = 1; ey <= n; ey++) {//end_y
						if (!dp[(i)%4][sx][sy][ex][ey])continue;
						for (int de = 0; de < 8; de++) {//move_end_point
							for (int ds = 0; ds < 8; ds++) {//move_start_point
								int nsx = sx + dx[ds];
								int nsy = sy + dy[ds];
								if (nsx<1 || nsx>n || nsy<1 || nsy>n)continue;
								int nex = ex + dx[de];
								int ney = ey + dy[de];
								if (nex<1 || nex>n || ney<1 || ney>n)continue;
								if (map[nsx][nsy] == map[nex][ney]) {
									dp[(i + 2)%4][nsx][nsy][nex][ney] += dp[i%4][sx][sy][ex][ey];
								}
							}
						}
						dp[i % 4][sx][sy][ex][ey] = 0;
					}
				}
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				for (int m = 1; m <= n; m++) {
					sum += dp[l%4][i][j][k][m];
				}
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}