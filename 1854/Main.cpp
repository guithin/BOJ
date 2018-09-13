#include<stdio.h>
#include <functional>
#include<memory.h>
#include<vector>
#include<queue>
using namespace std;

struct pos {
	int node, cost;
	pos() {};
	pos(int a, int b) {
		node = a;
		cost = b;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

int n, m, k;
vector<pos>vec[1010];
int dist[1010];
std::priority_queue<int>dest[1010];
queue<pos>q;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	memset(dist, 40, sizeof(dist));
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(pos(b, c));
//		vec[b].push_back(pos(a, c));
	}
	dest[1].push(0);
	q.push(pos(1, 0));
	while (q.size()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < vec[now.node].size(); i++) {
			if (dest[vec[now.node][i].node].size() < k) {
				dest[vec[now.node][i].node].push(now.cost + vec[now.node][i].cost);
				q.push(pos(vec[now.node][i].node, now.cost + vec[now.node][i].cost));
			}
			else if (dest[vec[now.node][i].node].top()>now.cost+vec[now.node][i].cost) {
				dest[vec[now.node][i].node].pop();
				dest[vec[now.node][i].node].push(now.cost + vec[now.node][i].cost);
				q.push(pos(vec[now.node][i].node, now.cost + vec[now.node][i].cost));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dest[i].size() < k)printf("-1\n");
		else printf("%d\n", dest[i].top());
	}
	return 0;
}