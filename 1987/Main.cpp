#include<stdio.h>
#include<queue>

int n, m;
int map[30][30] = { 0 };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ans = 0;

void back(int cur, int x, int y, int bit) {
	if (cur > ans)ans = cur;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] > n || x + dx[i] < 1 || y + dy[i] > m || y + dy[i] < 1)continue;
		if (bit&(1 << (map[x + dx[i]][y + dy[i]] - 'A')))continue;
		back(cur + 1, x + dx[i], y + dy[i], bit|(1 << (map[x + dx[i]][y + dy[i]] - 'A')));
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" ");
		for (int j = 1; j <= m; j++) {
			scanf("%c", &map[i][j]);
		}
	}
	back(1, 1, 1, (1<<(map[1][1]-'A')));
	printf("%d\n", ans);
	return 0;
}