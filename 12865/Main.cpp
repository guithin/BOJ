#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll w[110];
ll v[110];
ll dp[100010];

int main() {
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", w + i, v + i);
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = k; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	printf("%lld\n", dp[k]);
	return 0;
}