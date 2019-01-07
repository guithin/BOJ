#include<stdio.h>
#include<algorithm>
#include<vector>
#include<memory.h>
using namespace std;

typedef long long ll;

ll n;
ll inp[100010];
ll maxf[100010];
ll maxb[100010];
ll minf[100010];
ll minb[100010];

int main() {
	scanf("%lld", &n);
	memset(maxf, 0xb0, sizeof(maxf));
	memset(maxb, 0xb0, sizeof(maxb));
	memset(minf, 40, sizeof(minf));
	memset(minb, 40, sizeof(minb));
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
		maxf[i] = max(maxf[i - 1] + inp[i], inp[i]);
		minf[i] = min(minf[i - 1] + inp[i], inp[i]);
	}
	for (ll i = n; i; i--) {
		maxb[i] = max(maxb[i + 1] + inp[i], inp[i]);
		minb[i] = min(minb[i + 1] + inp[i], inp[i]);
	}
	for (int i = 1; i <= n; i++) {
		maxf[i] = max(maxf[i], maxf[i - 1]);
		minf[i] = min(minf[i], minf[i - 1]);
	}
	for (int i = n; i; i--) {
		maxb[i] = max(maxb[i + 1], maxb[i]);
		minb[i] = min(minb[i + 1], minb[i]);
	}
	ll ans = -1234567890;
	for (ll i = 1; i < n; i++) {
		ans = max({ ans, maxf[i] * maxb[i + 1], minf[i] * minb[i + 1] });
	}
	printf("%lld\n", ans);
	return 0;
}