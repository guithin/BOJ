#include<stdio.h>
#include<vector>
#include<queue>
#include<memory.h>
typedef long long ll;
/*
struct pos {
	ll to, cost;
	pos() {};
	pos(ll a, ll b) {
		to = a; cost = b;
	}
	bool operator<(const pos&io)const {
		return cost < io.cost;
	}
};

ll S, E, n;
std::vector<pos>vec[1010];
std::priority_queue<pos>q;
ll dest[1010];
*/

ll S, E, n;
ll map[1010][1010] = { 0 };
ll nod[1010][1010] = { 0 };

int main() {
//	freopen("7.in", "r", stdin);
	scanf("%lld %lld %lld", &S, &E, &n);
	memset(map, 40, sizeof(map));
	for (ll i = 1; i <= n; i++) {
		ll c, ni;
		scanf("%lld %lld", &c, &ni);
		std::vector<ll>temp;
		for (ll j = 1; j <= ni; j++) {
			ll qwer;
			scanf("%lld", &qwer);
			for (ll k = 0; k < temp.size(); k++) {
				if (map[temp[k]][qwer] > c) {
					map[temp[k]][qwer] = c;
					nod[temp[k]][qwer] = j - k - 1;
				}
				else if (map[temp[k]][qwer] == c&&nod[temp[k]][qwer] > j - k + 1)
					nod[temp[k]][qwer] = j - k - 1;
			}
			temp.push_back(qwer);
		}
	}
	for (ll k = 1; k <= 1000; k++) {
		for (ll i = 1; i <= 1000; i++) {
			for (ll j = 1; j <= 1000; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					nod[i][j] = nod[i][k] + nod[k][j];
				}
				else if (map[i][j] == map[i][k] + map[k][j] && nod[i][j] > nod[i][k] + nod[k][j])
					nod[i][j] = nod[i][k] + nod[k][j];
			}
		}
	}
	if (map[S][E] == map[0][0]) {
		printf("-1 -1\n");
	}
	else
		printf("%lld %lld\n", map[S][E], nod[S][E]);
	return 0;
}