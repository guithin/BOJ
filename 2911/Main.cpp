#include<stdio.h>
#include<algorithm>

typedef long long ll;

struct pos {
	ll p, c;
	pos() {}
	pos(ll a, ll b) {
		p = c;
		c = b;
	}
	bool operator<(const pos&io)const {
		return p < io.p;
	}
};

ll n, m;
pos inp[100010];

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", &inp[i].p, &inp[i].c);
	}
	std::sort(inp + 1, inp + 1 + n);
	ll sum = 0;
	ll now = 0;
	for (ll i = 1; i <= n; i++) {
		if (inp[i].c < now) {
			now = inp[i].c;
		}
		else if (inp[i].c > now) {
			sum += inp[i].c - now;
			now = inp[i].c;
		}
	}
	printf("%lld\n", sum);
	return 0;
}