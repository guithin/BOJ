#include<bits/stdc++.h>
using namespace std;

int n, m;
int inp[510][510];
int dp[5][510][510];
int ans = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void back(int x, int y, int from, int num, int sum) {
	if (num == 4) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i<4; i++) {
		if (dx[from] == -dx[i] && dy[from] == -dy[i])continue;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || nx>n || ny<1 || ny>m)continue;
		back(nx, ny, i, num + 1, sum + inp[nx][ny]);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &inp[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			back(i, j, 100, 1, inp[i][j]);

			for (int k = 0; k < 4; k++) {
				int temp = inp[i][j];
				for (int l = 0; l < 4; l++) {
					if (k == l)continue;
					int nx = i + dx[l];
					int ny = j + dy[l];
					if (nx<1 || nx>n || ny<1 || ny>m) {
						temp += -10000000;
						break;
					}
					temp += inp[nx][ny];
				}
				ans = max(temp, ans);
			}

		}
	}
	printf("%d\n", ans);
	return 0;
}