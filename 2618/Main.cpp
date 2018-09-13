#include<stdio.h>
#include<algorithm>
#include<memory.h>
#include<vector>
using namespace std;

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a; y = b;
	}
};

int n, w;
pos inp[1010];
int dp[2][1010][1010];
pos path[2][1010][1010];
bool chk[1010];

int absx(int x) {
	return x > 0 ? x : -x;
}

int dist(pos a, pos b) {
	return absx(a.x - b.x) + absx(a.y - b.y);
}
void func(int a, int b) {
	int temp = w;
	while (temp) {
		if (a)chk[b] = 1;
		else chk[temp] = 1;
		pos t = path[a][temp][b];
		a = t.x; b = t.y;
		temp--;
	}
}

int main() {
	scanf("%d %d", &n, &w);
	for (int i = 1; i <= w; i++) {
		scanf("%d %d", &inp[i].x, &inp[i].y);
	}
	memset(dp, 40, sizeof(dp));
	dp[1][0][0] = dp[0][0][0] = 0;
	dp[0][1][0] = dist(pos(1, 1), inp[1]);
	dp[1][1][0] = dist(pos(n, n), inp[1]);
	for (int i = 2; i <= w; i++) {
		if (dp[0][i][0] > dp[0][i - 1][0] + dist(inp[i - 1], inp[i])) {
			dp[0][i][0] = dp[0][i - 1][0] + dist(inp[i - 1], inp[i]);
			path[0][i][0] = pos(0, 0);
		}
		if (dp[1][i][0] > dp[1][i - 1][0] + dist(inp[i - 1], inp[i])) {
			dp[1][i][0] = dp[1][i - 1][0] + dist(inp[i - 1], inp[i]);
			path[1][i][0] = pos(1, 0);
		}
		if (dp[0][i][i - 1] > dp[1][i - 1][0] + dist(pos(1, 1), inp[i])) {
			dp[0][i][i - 1] = dp[1][i - 1][0] + dist(pos(1, 1), inp[i]);
			path[0][i][i - 1] = pos(1, 0);
		}
		if (dp[1][i][i - 1] > dp[0][i - 1][0] + dist(pos(n, n), inp[i])) {
			dp[1][i][i - 1] = dp[0][i - 1][0] + dist(pos(n, n), inp[i]);
			path[1][i][i - 1] = pos(0, 0);
		}
		for (int j = 1; j < i; j++) {
			if (dp[0][i][j] > dp[0][i - 1][j] + dist(inp[i - 1], inp[i])) {
				dp[0][i][j] = dp[0][i - 1][j] + dist(inp[i - 1], inp[i]);
				path[0][i][j] = pos(0, j);
			}
			if (dp[1][i][j] > dp[1][i - 1][j] + dist(inp[i - 1], inp[i])) {
				dp[1][i][j] = dp[1][i - 1][j] + dist(inp[i - 1], inp[i]);
				path[1][i][j] = pos(1, j);
			}
			if (dp[0][i][i - 1] > dp[1][i - 1][j] + dist(inp[j], inp[i])) {
				dp[0][i][i - 1] = dp[1][i - 1][j] + dist(inp[j], inp[i]);
				path[0][i][i - 1] = pos(1, j);
			}
			if (dp[1][i][i - 1] > dp[0][i - 1][j] + dist(inp[j], inp[i])) {
				dp[1][i][i - 1] = dp[0][i - 1][j] + dist(inp[j], inp[i]);
				path[1][i][i - 1] = pos(0, j);
			}
		}
	}
	int mini = 100000000;
	int a, b;
	for (int i = 0; i < w; i++) {
		if (mini > dp[0][w][i]) {
			mini = dp[0][w][i]; a = 0; b = i;
		}
		if (mini >= dp[1][w][i]) {
			mini = dp[1][w][i]; a = 1; b = i;
		}
	}
	printf("%d\n", mini);
	func(a, b);
	for (int i = 1; i <= w; i++) {
		if (chk[i])printf("1\n");
		else printf("2\n");
	}
	return 0;
}