#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s;
ll ans;
char str[3010];
ll dp[3010][3010];
const ll mod = 1000000007;

int main() {
	scanf("%lld", &s);
	scanf("%s", str);
	dp[0][0] = 1;
	ll len = strlen(str);
	for (ll i = 0; i <= 25; i++) {
		dp[1][i] = 1;
	}
	for (ll i = 2; i <= len; i++) {
		dp[i][0] = 1;
		for (ll j = 1; j <= s; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			if (j > 25) {
				dp[i][j] -= dp[i - 1][j - 26];
			}
			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}
	printf("%lld\n", dp[len][s]);
	return 0;
}