#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;

struct start {
	const ll inf = 1234567890;

	struct pos {
		ll node, cost;
		pos() {};
		pos(ll a, ll b) {
			node = a;
			cost = b;
		}
		bool operator<(const pos&io)const {
			return cost > io.cost;
		}
		bool operator==(const pos&io)const {
			return node == io.node;
		}
	};

	ll n, m, s, e;
	vector<pos>vec[510];
	ll dist[510];
	vector<ll>path[510];
	priority_queue<pos>q;
/*
	ll find(ll node, ll val) {
		ll l = 0;
		ll r = vec[node].size() - 1;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (vec[node][mid].node < val)
				r = mid - 1;
			else if (vec[node][mid].node > val)
				l = mid + 1;
			else
				return mid;
		}
		while (1) {}
		return l;
	}
*/
	ll find(ll node, ll val) {
		for (ll i = 0; i < vec[node].size(); i++) {
			if (vec[node][i].node == val)return i;
		}
		return -1;
	}

	ll main() {
		memset(dist, 40, sizeof(dist));
		scanf("%lld %lld", &n, &m);
		if (!n && !m)return 1;
		scanf("%lld %lld", &s, &e);
		s++; e++;
		for (ll i = 1; i <= m; i++) {
			ll a, b, c;
			scanf("%lld %lld %lld", &a, &b, &c);
			a++; b++;
			vec[a].push_back(pos(b, c));
		}
		dist[s] = 0;
		q.push(pos(s, 0));
		while (q.size()) {
			pos now = q.top(); q.pop();
			for (ll i = 0; i < vec[now.node].size(); i++) {
				if (dist[vec[now.node][i].node] > vec[now.node][i].cost + now.cost) {
					dist[vec[now.node][i].node] = vec[now.node][i].cost + now.cost;
					path[vec[now.node][i].node].clear();
					path[vec[now.node][i].node].push_back(now.node);
					q.push(pos(vec[now.node][i].node, dist[vec[now.node][i].node]));
				}
				else if (dist[vec[now.node][i].node] == vec[now.node][i].cost + now.cost) {
					path[vec[now.node][i].node].push_back(now.node);
				}
			}
		}
/*
		for (ll i = 1; i <= n; i++) {
			sort(vec[i].begin(), vec[i].end());
		}
*/
		queue<ll>que;
		que.push(e);
		while (que.size()) {
			ll now = que.front(); que.pop();
			for (ll i = 0; i < path[now].size(); i++) {
				vec[path[now][i]][find(path[now][i], now)].cost = inf;
				que.push(path[now][i]);
			}
		}
		memset(dist, 40, sizeof(dist));
		dist[s] = 0;
		q.push(pos(s, 0));
		while (q.size()) {
			pos now = q.top(); q.pop();
			for (ll i = 0; i < vec[now.node].size(); i++) {
				if (dist[vec[now.node][i].node] > vec[now.node][i].cost + now.cost) {
					dist[vec[now.node][i].node] = vec[now.node][i].cost + now.cost;
					q.push(pos(vec[now.node][i].node, dist[vec[now.node][i].node]));
				}
			}
		}
		if (dist[e] >= inf) {
			printf("-1\n");
		}
		else
			printf("%lld\n", dist[e]);
		return 0;
	}
};

int main() {
	while (1) {
		start temp;
		if (temp.main())break;
	}
	return 0;
}