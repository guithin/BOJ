#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
typedef long long ll;

struct pos {
	ll node, cost, num;
	pos() {};
	pos(ll a, ll b, ll c) {
		node = a;
		cost = b;
		num = c;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

ll v, e, k;
std::vector<pos>vec[10010];
std::priority_queue<pos>q;
ll dist[30][10010];

int main() {
	scanf("%lld %lld %lld", &v, &e, &k);
	for (ll i = 1; i <= e; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		vec[a].push_back(pos(b, c, 0));
		vec[b].push_back(pos(a, c, 0));
	}
	memset(dist, 40, sizeof(dist));
	for (ll i = 0; i <= k; i++) {
		dist[i][1] = 0;
	}
	q.push(pos(1, 0, 0));
	while (q.size()) {
		pos now = q.top(); q.pop();
		for (ll i = 0; i < vec[now.node].size(); i++) {
			if (dist[now.num][vec[now.node][i].node] > dist[now.num][now.node] + vec[now.node][i].cost) {
				dist[now.num][vec[now.node][i].node] = dist[now.num][now.node] + vec[now.node][i].cost;
				q.push(pos(vec[now.node][i].node, dist[now.num][vec[now.node][i].node], now.num));
			}
			if (now.num<k&&dist[now.num + 1][vec[now.node][i].node] > dist[now.num][now.node]) {
				dist[now.num + 1][vec[now.node][i].node] = dist[now.num][now.node];
				q.push(pos(vec[now.node][i].node, dist[now.num + 1][vec[now.node][i].node], now.num + 1));
			}
		}
	}
	printf("%lld\n", dist[k][v]);
	return 0;
}