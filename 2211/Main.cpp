#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

struct pos {
	int node1, node2, cost;
	pos() {};
	pos(int a, int b, int c) {
		node1 = a; node2 = b; cost = c;
	}
	bool operator < (const pos&io) const{
		return cost > io.cost;
	}
};

struct val {
	int node, cost;
	val() {};
	val(int a, int b) {
		node = a; cost = b;
	}
	bool operator < (const val&io)const {
		return cost > io.cost;
	}
};

priority_queue<pos>q;
priority_queue<val>dq;
vector<val>vec[1010];
vector<val>save;
int dist[1010];
int path[1010];
int table[1010];
int n, m;
int cnt = 0;

int find(int x) {
	if (table[x] == x)return x;
	return table[x] = find(table[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)table[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		q.push(pos(a, b, c));
		vec[a].push_back(val(b, c));
		vec[b].push_back(val(a, c));
	}
	memset(dist, 40, sizeof(dist));
	dist[1] = 0;
	dq.push(val(1, 0));
	while (dq.size()) {
		val now = dq.top(); dq.pop();
		for (int i = 0; i < vec[now.node].size(); i++) {
			if (dist[vec[now.node][i].node] > dist[now.node] + vec[now.node][i].cost) {
				dist[vec[now.node][i].node] = dist[now.node] + vec[now.node][i].cost;
				path[vec[now.node][i].node] = now.node;
				dq.push(val(vec[now.node][i].node, dist[vec[now.node][i].node]));
			}
		}
	}
	printf("%d\n", n-1);
	for (int i = 2; i <= n; i++) {
		printf("%d %d\n", path[i], i);
	}
	return 0;
}