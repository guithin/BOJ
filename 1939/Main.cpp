#include<stdio.h>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

struct pos {
	int node, cost;
	pos() {};
	pos(int a, int b) {
		node = a; cost = b;
	}
};

int n, m;
vector<pos>vec[10010];
queue<int>q;
int ans[10010];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
		vec[b].push_back(pos(a, c));
	}
	int a, b;
	scanf("%d %d", &a, &b);
	ans[a] = 1 << 30;
	q.push(a);
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			if (ans[vec[now][i].node] < min(ans[now], vec[now][i].cost)) {
				ans[vec[now][i].node] = min(ans[now], vec[now][i].cost);
				q.push(vec[now][i].node);
			}
		}
	}
	printf("%d\n", ans[b]);
	return 0;
}