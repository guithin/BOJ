#include<stdio.h>
#include<queue>
using namespace std;

struct pos {
	int node, val;
	pos() {};
	pos(int a, int b) {
		node = a; val = b;
	}
};

int n, m, k;
int map[310][310];
int maxi[310][310];
queue<pos>q;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a > b)continue;
		if (map[a][b] < c)
			map[a][b] = c;
	}
	q.push(pos(1, 1));
	while (q.size()) {
		pos now = q.front(); q.pop();
		for (int i = 1; i <= n; i++) {
			if (!map[now.node][i])continue;
			if (maxi[i][now.val + 1] < maxi[now.node][now.val] + map[now.node][i]) {
				maxi[i][now.val + 1] = maxi[now.node][now.val] + map[now.node][i];
				if (now.val + 1 < m)
					q.push(pos(i, now.val + 1));
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (maxi[n][i] > ans)ans = maxi[n][i];
	}
	printf("%d\n", ans);
	return 0;
}