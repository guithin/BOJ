#include<stdio.h>
#include<queue>
#include<vector>
#include<memory.h>

struct pos {
	int x, cost;
	pos() {};
	pos(int a, int c) {
		x = a;
		cost = c;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

int n, m, x;
std::vector<pos>vec[1010];
int ans = 0;
int dest[1010][1010] = { 0 };

int main() {
	memset(dest, 40, sizeof(dest));
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 1; i <= n; i++)dest[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
	}
	int ans = 0;
	for (int start = 1; start <= n; start++) {
		dest[start][start] = 0;
		std::priority_queue<pos>q;
		q.push(pos(start, 0));
		while (q.size()) {
			pos now = q.top();
			q.pop();
			if (now.x == x&&start != x)break;
			for (int i = 0; i < vec[now.x].size(); i++) {
				if (dest[start][vec[now.x][i].x] > dest[start][now.x] + vec[now.x][i].cost) {
					dest[start][vec[now.x][i].x] = dest[start][now.x] + vec[now.x][i].cost;
					q.push(pos(vec[now.x][i].x, dest[start][vec[now.x][i].x]));
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ans < dest[i][x] + dest[x][i])ans = dest[i][x] + dest[x][i];
	}
	printf("%d\n", ans);
	return 0;
}