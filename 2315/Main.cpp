#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s;
ll inp[1010];
ll sov[1010];
ll save[1010][1010];
ll sove[1010][1010];
ll dp[1010][1010][2];

int main() {
	scanf("%lld %lld", &n, &s);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", inp + i, sov + i);
		sove[i][i] = sov[i];
	}
	for (ll i = n; i >= 1; i--) {
		inp[i] -= inp[i - 1];
	}
	for (ll i = 1; i < n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			save[j][i] = save[i][j] = save[i][j - 1] + inp[j];
			sove[i][j] = sove[i][j - 1] + sov[j];
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			dp[i][j][0] = dp[i][j][1] = (ll)1234567890;
		}
	}
	memset(dp, 10, sizeof(dp));
	dp[s][s][0] = dp[s][s][1] = 0;

	for (ll i = s; i >= 1; i--) {
		for (ll j = s; j <= n; j++) {

			if (dp[i][j][0] > dp[i + 1][j][1] + save[i][j] * (sove[1][i] + sove[j + 1][n])) {
				dp[i][j][0] = dp[i + 1][j][1] + save[i][j] * (sove[1][i] + sove[j + 1][n]);
			}

			if (dp[i][j][0] > dp[i + 1][j][0] + save[i][i + 1] * (sove[1][i] + sove[j + 1][n])) {
				dp[i][j][0] = dp[i + 1][j][0] + save[i][i + 1] * (sove[1][i] + sove[j + 1][n]);
			}

			if (dp[i][j][1] > dp[i][j - 1][0] + save[i][j] * (sove[1][i - 1] + sove[j][n])) {
				dp[i][j][1] = dp[i][j - 1][0] + save[i][j] * (sove[1][i - 1] + sove[j][n]);
			}

			if (dp[i][j][1] > dp[i][j - 1][1] + save[j - 1][j] * (sove[1][i - 1] + sove[j][n])) {
				dp[i][j][1] = dp[i][j - 1][1] + save[j - 1][j] * (sove[1][i - 1] + sove[j][n]);
			}

		}
	}
	printf("%lld\n", min(dp[1][n][0], dp[1][n][1]));
	return 0;
}
