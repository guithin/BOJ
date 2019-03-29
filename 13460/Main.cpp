#include<stdio.h>
#include<vector>
#include<stdlib.h>
using namespace std;

struct pos {
	int x, y;
	pos() {}
	pos(int q, int w) {
		x = q; y = w;
	}
};

int n, m;
char inp[15][15];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int ans = 10000000;
pos O;

void back(pos r, pos b, int cnt, int j) {
	if (cnt > 10)
		return;
	for (int i = 0; i < 4; i++) {
		if (i == j)continue;
		int rx = r.x, ry = r.y, bx = b.x, by = b.y;
		bool flag = true;
		bool holeR = false, holeB = false;
		while (flag) {
			bool rmove = holeR ? false : inp[rx + dx[i]][ry + dy[i]] == '.' && !(rx + dx[i] == bx && ry + dy[i] == by);
			if (rmove) {
				rx += dx[i];
				ry += dy[i];
				if (rx == O.x&&ry == O.y) {
					rx = ry = -1;
					holeR = true;
				}
			}
			bool bmove = holeB ? false : inp[bx + dx[i]][by + dy[i]] == '.' && !(bx + dx[i] == rx && by + dy[i] == ry);
			if (bmove) {
				bx += dx[i];
				by += dy[i];
				if (bx == O.x && by == O.y) {
					rx = ry = -1;
					holeB = true;
				}
			}
			flag = rmove || bmove;
		}
		if (holeB) {
			continue;
		}
		else if (holeR) {
			if (ans > cnt)ans = cnt;
			continue;
		}
		back(pos(rx, ry), pos(bx, by), cnt + 1, i);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	pos sr, sb;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp[i] + 1);
		for (int j = 1; j <= m; j++) {
			if (inp[i][j] == 'R') {
				sr = pos(i, j);
				inp[i][j] = '.';
			}
			else if (inp[i][j] == 'B') {
				sb = pos(i, j);
				inp[i][j] = '.';
			}
			else if (inp[i][j] == 'O') {
				O = pos(i, j);
				inp[i][j] = '.';
			}
		}
	}
	back(sr, sb, 1, -1);
	printf("%d\n", ans > 10 ? -1 : ans);
	return 0;
}