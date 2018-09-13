#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
typedef long long ll;
long long INF = 1000000000;

struct pos {
	ll to, cost;
	pos() {};
	pos(ll a, ll b) {
		to = a;
		cost = b;
	}
	bool operator<(const pos&io)const {
		return cost > io.cost;
	}
};

std::priority_queue<pos>q;
std::vector<pos>vec[1010];

ll n, m;

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= m; i++) {
		ll a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		vec[a].push_back(pos(b, c));
		vec[b].push_back(pos(a, c));
	}

	ll stable[1010];
	for (ll i = 0; i <= n; i++)stable[i] = INF;
	stable[1] = 0;
	q.push(pos(1, 0));
//	for (ll i = 2; i <= n; i++)q.push(pos(i, stable[i]));
	while(!q.empty()) {
		ll now = q.top().to;
		ll ncost = q.top().cost;
		q.pop();
		for (ll j = 0; j < vec[now].size(); j++) {
			if (ncost + vec[now][j].cost < stable[vec[now][j].to]) {
				stable[vec[now][j].to] = ncost + vec[now][j].cost;
				q.push(pos(vec[now][j].to, stable[vec[now][j].to]));
			}
		}
	}
	ll ans = -1;
	for (ll node = 1; node <= n; node++) {
		for (ll e = 0; e < vec[node].size(); e++) {
			while (q.size())q.pop();
			ll temp = vec[node][e].cost;
			vec[node][e].cost = stable[0];
			ll table[1010];
			for (ll i = 0; i <= n; i++)table[i] = INF;
			table[1] = 0;
			q.push(pos(1, 0));
//			for (ll i = 2; i <= n; i++)q.push(pos(i, table[i]));
			while(!q.empty()) {
				ll now = q.top().to;
				ll ncost = q.top().cost;
				q.pop();
				for (ll j = 0; j < vec[now].size(); j++) {
					if (ncost + vec[now][j].cost < table[vec[now][j].to]) {
						table[vec[now][j].to] = ncost + vec[now][j].cost;
						q.push(pos(vec[now][j].to, table[vec[now][j].to]));
					}
				}
			}
			ans = ans < table[n] ? table[n] : ans;
			vec[node][e].cost = temp;
		}
	}
	if (ans >= INF || ans==-1)printf("-1\n");
	else printf("%lld\n", ans - stable[n]);
//	printf("%lld %lld\n", ans,  stable[n]);
	return 0;
}