#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

ll dp[12][101][101][101];

ll combi[11][11];


int main() {
	combi[0][0] = 1;
	for (ll i = 1; i <= 10; i++) {
		combi[i][0] = 1;
		for (ll j = 1; j <= i; j++) {
			combi[i][j] = combi[i - 1][j] + combi[i - 1][j - 1];
		}
	}

	ll n, R, G, B;
	scanf("%lld %lld %lld %lld", &n, &R, &G, &B);
	dp[0][R][G][B] = 1;

	if (R)dp[1][R - 1][G][B] = 1;
	if (G)dp[1][R][G - 1][B] = 1;
	if (B)dp[1][R][G][B - 1] = 1;

	for (ll i = 1; i <= n; i++) {
		for (ll r = 0; r <= R; r++) {
			for (ll g = 0; g <= G; g++) {
				for (ll b = 0; b <= B; b++) {
					ll val = dp[i][r][g][b];
					if (!val)continue;
					if (r >= i + 1) {//use r
						dp[i + 1][r - i - 1][g][b] += val;
					}
					if (g >= i + 1) {//use g
						dp[i + 1][r][g - i - 1][b] += val;
					}
					if (b >= i + 1) {//use b
						dp[i + 1][r][g][b - i - 1] += val;
					}
					if (!((i + 1) & 1)) {//use 2 colors
						if (r >= (i + 1) / 2 && g >= (i + 1) / 2) {
							dp[i + 1][r - (i + 1) / 2][g - (i + 1) / 2][b] += val * combi[i + 1][(i + 1) / 2];
						}
						if (g >= (i + 1) / 2 && b >= (i + 1) / 2) {
							dp[i + 1][r][g - (i + 1) / 2][b - (i + 1) / 2] += val * combi[i + 1][(i + 1) / 2];
						}
						if (r >= (i + 1) / 2 && b >= (i + 1) / 2) {
							dp[i + 1][r - (i + 1) / 2][g][b - (i + 1) / 2] += val * combi[i + 1][(i + 1) / 2];
						}
					}
					if (!((i + 1) % 3)) {//use 3 colors
						if (r >= (i + 1) / 3 && g >= (i + 1) / 3 && b >= (i + 1) / 3) {
							dp[i + 1][r - (i + 1) / 3][g - (i + 1) / 3][b - (i + 1) / 3] += val * combi[i + 1][(i + 1) / 3] * combi[(i + 1) - (i + 1) / 3][(i + 1) / 3];
						}
					}
				}
			}
		}
	}
	ll sum = 0;
	for (ll i = 0; i <= R; i++) {
		for (ll j = 0; j <= G; j++) {
			for (ll k = 0; k <= B; k++) {
				sum += dp[n][i][j][k];
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}