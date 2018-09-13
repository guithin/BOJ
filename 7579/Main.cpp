#include<stdio.h>
#include<algorithm>
using namespace std;

typedef long long ll;

struct dynamic {
	ll mem;
	ll val;
	dynamic() {};
	dynamic(ll a, ll b) {
		mem == a;
		val = b;
	}
};

ll mem[110] = { 0 };
ll cost[10010] = { 0 };
ll dp[10010] = { 0 };

int main() {
	ll n, m;
	ll temp1 = 0;
	ll temp2 = 0;
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", mem + i);
		temp1 += mem[i];
	}
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", cost + i);
		temp2 += cost[i];
	}
	ll new_m = temp1 - m;
	for (ll i = 1; i <= n; i++) {
		for (ll j = temp2; j - cost[i] >= 0; j--) {
			dp[j] = max(dp[j], dp[j-cost[i]]+mem[i]);
		}
	}
	for (ll i = 0; i <= temp2; i++) {
		if (dp[i] >= m) {
			printf("%lld\n", i);
			return 0;
		}
	}
//	printf("%lld\n", dp[temp2]);
	for (ll i = 0; i <= temp2; i++) {
		printf("%lld %lld\n", i, dp[i]);
	}
	return 0;
}