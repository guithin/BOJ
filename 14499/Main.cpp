#include<stdio.h>

int map[1010][1010] = { 0 };
int ju[10] = { 0 };

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

void change(int cur) {
	if (cur == 1) {
		int temp = ju[1];
		ju[1] = ju[4];
		ju[4] = ju[6];
		ju[6] = ju[3];
		ju[3] = temp;
		return;
	}
	if (cur == 2) {
		int temp = ju[1];
		ju[1] = ju[3];
		ju[3] = ju[6];
		ju[6] = ju[4];
		ju[4] = temp;
		return;
	}
	if (cur == 3) {
		int temp = ju[1];
		ju[1] = ju[5];
		ju[5] = ju[6];
		ju[6] = ju[2];
		ju[2] = temp;
		return;
	}
	if (cur == 4) {
		int temp = ju[1];
		ju[1] = ju[2];
		ju[2] = ju[6];
		ju[6] = ju[5];
		ju[5] = temp;
		return;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int x, y;
	scanf("%d %d", &x, &y);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= T; i++) {
		int temp;
		scanf("%d", &temp);
		if (x + dx[temp] < 0 || x + dx[temp] >= n || y + dy[temp] < 0 || y + dy[temp] >= m)continue;
		x += dx[temp];
		y += dy[temp];
		change(temp);
		if (map[x][y] != 0) {
			ju[6] = map[x][y];
			map[x][y] = 0;
		}
		else
			map[x][y] = ju[6];
		printf("%d\n", ju[1]);
	}
	return 0;
}