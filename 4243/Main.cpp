#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inp[110];
ll dist[110][110];
ll dp[110][110][2];

int main() {
	ll n, s, t;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &n, &s);
		memset(inp, 0, sizeof(inp));
		for (ll i = 1; i < n; i++) {
			scanf("%lld", inp + i);
		}
		memset(dist, 0, sizeof(dist));
		for (ll i = 1; i < n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				dist[i][j] = dist[j][i] = dist[i][j - 1] + inp[j - 1];
			}
		}
		for (ll i = 0; i <= n; i++) {
			for (ll j = 0; j <= n; j++) {
				dp[i][j][0] = dp[i][j][1] = (ll)15000000000000000;
			}
		}
		dp[s][s][0] = dp[s][s][1] = 0;

		for (ll i = s; i >= 1; i--) {
			for (ll j = s; j <= n; j++) {

				if (dp[i][j][0] > dp[i + 1][j][1] + dist[i][j] * (n - j + i)) {
					dp[i][j][0] = dp[i + 1][j][1] + dist[i][j] * (n - j + i);
				}

				if (dp[i][j][0] > dp[i + 1][j][0] + dist[i + 1][i] * (n - j + i)) {
					dp[i][j][0] = dp[i + 1][j][0] + dist[i + 1][i] * (n - j + i);
				}

				if (dp[i][j][1] > dp[i][j - 1][0] + dist[i][j] * (n - j + i)) {
					dp[i][j][1] = dp[i][j - 1][0] + dist[i][j] * (n - j + i);
				}

				if (dp[i][j][1] > dp[i][j - 1][1] + dist[j][j - 1] * (n - j + i)) {
					dp[i][j][1] = dp[i][j - 1][1] + dist[j][j - 1] * (n - j + i);
				}
			}
		}
		printf("%lld\n", min(dp[1][n][0], dp[1][n][1]));
	}
	return 0;
}