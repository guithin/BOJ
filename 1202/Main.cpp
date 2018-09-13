#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

struct pos {
	ll val, cost;
	pos() {};
	pos(ll a, ll b) {
		val = a; cost = b;
	}
	bool operator<(const pos&io)const {
		return val < io.val;
	}
};

ll n, k;
ll inp[300010];
pos temp[300010];
priority_queue<pos>q;

bool cmp(pos &a, pos &b) {
	return a.cost < b.cost;
}

int main() {
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &temp[i].cost, &temp[i].val);
	}
	sort(temp + 1, temp + 1 + n, cmp);
	for (ll i = 1; i <= k; i++) {
		scanf("%lld", inp + i);
	}
	sort(inp + 1, inp + 1 + k);
	ll idx = 1;
	ll sum = 0;
	for (ll i = 1; i <= k; i++) {
		while (inp[i] >= temp[idx].cost && idx <= n) {
			q.push(temp[idx]);
			idx++;
		}
		if (q.size()) {
			sum += q.top().val; q.pop();
		}
	}
	printf("%lld\n", sum);
	return 0;
}