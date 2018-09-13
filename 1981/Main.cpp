#include<stdio.h>
#include<vector>
#include<queue>

struct pos {
	int x, y;
	pos() {};
	pos(int a, int b) {
		x = a;
		y = b;
	}
};

int n;
int map[110][110] = { 0 };
int dx[8] = { 0,0,1,-1, 1, 1, -1, -1 };
int dy[8] = { 1,-1,0,0, 1, -1, 1, -1 };

bool isok(int l, int h) {
	std::queue<pos>q;
	bool chk[110][110] = { 0 };
	if (map[1][1] >= l&&map[1][1] <= h) {
		q.push(pos(1, 1));
		chk[1][1] = true;
	}
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (now.x + dx[i]<1 || now.x + dx[i]>n || now.y + dy[i]<1 || now.y + dy[i]>n)continue;
			if (chk[now.x + dx[i]][now.y + dy[i]])continue;
			if (map[now.x + dx[i]][now.y + dy[i]] >= l&&map[now.x + dx[i]][now.y + dy[i]] <= h) {
				chk[now.x + dx[i]][now.y + dy[i]] = true;
				q.push(pos(now.x + dx[i], now.y + dy[i]));
			}
		}
	}
	return chk[n][n];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int mini = map[n][n];
	int maxi = map[n][n];
	int l = -1;
	int r = 0;
	int ans = 10000000;
	while (1) {
		if (r > 200 || l > mini)break;
		l++;
		int tl = r;
		int tr = 200;
		while (tl <= tr) {
			int mid = (tl + tr) / 2;
			if (isok(l, mid)) {
				tr = mid - 1;
			}
			else {
				tl = mid + 1;
			}
		}
		r = tl;
		tl = l;
		tr = r;
		while (tl <= tr) {
			int mid = (tl + tr) / 2;
			if (isok(mid, r)) {
				tl = mid + 1;
			}
			else {
				tr = mid - 1;
			}
		}
		l = tr;
		if (r - l < ans)ans = r - l;
	}
	printf("%d\n", ans);
	return 0;
}