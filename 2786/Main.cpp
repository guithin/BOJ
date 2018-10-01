#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct pos {
	ll a, b, idx;
	bool operator<(const pos&io)const {
		return a > io.a;
	}
};

ll n;
pos inp[500010];
bool chk[500010];
priority_queue<pos>q;

bool cmp(const pos& i, const pos& io) {
	if (i.b == io.b)return i.a < io.a;
	return i.b < io.b;
}

int main() {
	scanf("%lld", &n);
	inp[0].a = inp[0].b = 1000000000;
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &inp[i].a, &inp[i].b);
	}
	sort(inp + 1, inp + 1 + n, cmp);
	for (ll i = 1; i <= n; i++) {
		inp[i].idx = i;
		q.push(inp[i]);
	}
	ll idx = 1;
	ll temp = q.top().idx; chk[temp] = 1;
	ll ans = 0; q.pop();
	printf("%lld\n", inp[temp].a);



	for (ll i = 2; i <= n; i++) {
		while (chk[q.top().idx])q.pop();
		while (chk[idx])idx++;

		ll val1 = inp[temp].a + inp[idx].b;
		ll val2 = inp[temp].b + q.top().a;

		if (val1 > val2) {
			ans += inp[temp].b;
			temp = q.top().idx; q.pop();
			chk[temp] = true;
		}
		else {
			ans += inp[idx].b;
			chk[idx] = 1; idx++;
		}

		printf("%lld\n", ans + inp[temp].a);
	}
	return 0;
}