#include<stdio.h>

int dx[8] = { 0,0,-1,1,1,-1, 1, -1 };
int dy[8] = { 1,-1,0,0,1,-1, -1, 1 };
int map[30][30] = { 0 };
long long cnt = 0;

void dfs(int n, int idx) {
	if (idx == n + 1) {
		cnt++;
//		printf("%d\n", cnt);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (map[idx][i] <0)continue;
		map[idx][i] = 1;
		for (int j = 0; j < 8; j++) {
			for (int k = 1; idx + dx[j] * k <= n && idx + dx[j] * k >= 1 && i + dy[j] * k >= 1 && i + dy[j] * k <= n; k++) {
				map[idx + dx[j] * k][i + dy[j] * k] --;
			}
		}
		dfs(n, idx + 1);
		map[idx][i] = 0;
		for (int j = 0; j < 8; j++) {
			for (int k = 1; idx + dx[j] * k <= n && idx + dx[j] * k >= 1 && i + dy[j] * k >= 1 && i + dy[j] * k <= n; k++) {
				map[idx + dx[j] * k][i + dy[j] * k] ++;
			}
		}
	}
}


int main() {
	int n;
	scanf("%d", &n);
	dfs(n, 1);
	printf("%lld\n", cnt);
	return 0;
}