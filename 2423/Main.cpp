#include<bits/stdc++.h>
using namespace std;

struct pos {
	int i, j, v;
	pos() {};
	pos(int _i, int _j, int _v) {
		i = _i; j = _j; v = _v;
	}
	bool operator<(const pos& io)const {
		return v > io.v;
	}
};

int n, m;
int inp[510][510];
int dist[510][510];
priority_queue<pos>q;

int dx[6] = { 0, 0, 1, 1, -1, -1 };
int dy[2][6] = { {1, -1, 0, 1, 0, -1},	// != / i+j&1
				 {1, -1, 0, -1, 0, 1} };// == /

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf(" ");
		for (int j = 1; j <= m; j++) {
			char c = getchar();
			if (i + j & 1) {
				inp[i][j] = c != '/';
			}
			else {
				inp[i][j] = c == '/';
			}
		}
	}
	if (n + m & 1) {
		printf("NO SOLUTION\n");
		return 0;
	}
	memset(dist, 40, sizeof(dist));
	dist[1][1] = inp[1][1];
	q.push(pos(1, 1, dist[1][1]));
	while(q.size()) {
		pos now = q.top(); q.pop();
		int sel = now.i + now.j & 1;
		for (int i = 0; i < 6; i++) {
			int nx = now.i + dx[i];
			int ny = now.j + dy[sel][i];
			if (nx<1 || nx>n || ny<1 || ny>m)continue;
			if (dist[nx][ny] > dist[now.i][now.j] + inp[nx][ny]) {
				dist[nx][ny] = dist[now.i][now.j] + inp[nx][ny];
				q.push(pos(nx, ny, dist[nx][ny]));
			}
		}
	}
	printf("%d\n", dist[n][m]);
	return 0;
}