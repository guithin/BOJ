#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

ll n;
ll in1[100010];
ll in2[100010];
ll dp[100010][2];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", in1 + i);
	}
	for (ll i = 1; i < n; i++) {
		scanf("%lld", in2 + i);
	}
	dp[1][0] = in1[1];
	dp[1][1] = in2[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] += (dp[i - 1][0] * ((in1[i] + in2[i - 1]) % mod)) % mod;
		dp[i][0] += (dp[i - 1][1] * ((in1[i] + in2[i - 1] - 1) % mod)) % mod;
		dp[i][0] %= mod;
		dp[i][1] = (((dp[i - 1][0] + dp[i - 1][1]) % mod)*in2[i]) % mod;
	}
	printf("%lld\n", dp[n][0]);
	return 0;
}