#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
char inp[20][20];
ll dp[15][17000];
ll w[10][10] = {
	{ 0 },
{ 0, 10, 8, 7, 5, 1 },
{ 0, 8, 6, 4, 3, 1 },
{ 0, 7, 4, 3, 2, 1 },
{ 0, 5, 3, 2, 2, 1 },
{ 0, 1, 1, 1, 1, 0 },
};

void back(ll now, ll bit, ll sum) {
	if (now > m + 1)return;
	if (now == m + 1) {
		dp[1][bit] = max(dp[1][bit], sum);
		return;
	}
	back(now + 1, bit, sum);
	back(now + 1, bit | (1ll << (now - 1)), sum);
	back(now + 2, bit | (1ll << (now - 1)) | (1ll << (now)), sum + w[inp[1][now]][inp[1][now + 1]]);
}

void func(ll cur, ll line, ll bit_now, ll bit_nxt, ll sum) {
	if (cur > m + 1)return;
	if (cur == m + 1) {
		ll biit = bit_now^((1ll<<m)-1);
		dp[line][bit_nxt] = max(dp[line][bit_nxt], dp[line - 1][biit] + sum);
		return;
	}
	func(cur + 1, line, bit_now, bit_nxt, sum);
	func(cur + 1, line, bit_now, bit_nxt | (1ll << (cur - 1)), sum);
	func(cur + 1, line, bit_now | (1ll << (cur - 1)), bit_nxt | (1ll << (cur - 1)), sum + w[inp[line - 1][cur]][inp[line][cur]]);
	func(cur + 2, line, bit_now, bit_nxt | (1ll << (cur - 1)) | (1ll << (cur)), sum + w[inp[line][cur]][inp[line][cur + 1]]);
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			char c; scanf(" %c", &c);
			inp[i][j] = c - 'A' + 1;
			if (inp[i][j] == 6)inp[i][j]--;
		}
	}
	back(1, 0, 0);
	for (ll i = 2; i <= n; i++) {
		func(1, i, 0, 0, 0);
	}

	ll ans = 0;
	for (ll i = 0; i < (1ll << m); i++) {
		ans = max(ans, dp[n][i]);
	}
	printf("%lld\n", ans);
	return 0;
}