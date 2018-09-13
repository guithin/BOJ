#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll inp[55][55];
ll xc[15];
ll yc[15];
ll idx1 = 1;
ll xh[110];
ll yh[110];
ll idx2 = 1;
ll dist[15][110];
ll ans = 900000000000000000;

void back(ll now, ll num, ll bit) {
	if (now == idx1 + 1) {
		/*
		for (int i = 0; i < idx1; i++) {
			printf("%d ", bit&(1 << i) ? 1 : 0);
		}
		printf("\n");
		//*/
		ll arr[110]; memset(arr, 40, sizeof(arr));
		for (ll i = 1; i <= idx1; i++) {
			if (bit&(1ll << (i - 1))) {
				for (ll j = 1; j <= idx2; j++) {
					arr[j] = min(arr[j], dist[i][j]);
				}
			}
		}
		ll temp = 0;
		for (ll i = 1; i <= idx2; i++)temp += arr[i];
		ans = min(ans, temp);
		return;
	}
	if (num < m) {
		back(now + 1, num + 1, bit | (1ll << (now - 1)));
	}
	if (idx1 - now >= m - num) {
		back(now + 1, num, bit);
	}
}

int main() {
	scanf("%lld %lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			scanf("%lld", &inp[i][j]);
			if (inp[i][j] == 2) {
				xc[idx1] = i; yc[idx1] = j; idx1++;
			}
			else if (inp[i][j] == 1) {
				xh[idx2] = i; yh[idx2] = j; idx2++;
			}
		}
	}
	idx1--; idx2--;
	for (ll i = 1; i <= idx1; i++) {
		for (ll j = 1; j <= idx2; j++) {
			dist[i][j] = abs(xh[j] - xc[i]) + abs(yh[j] - yc[i]);
		}
	}
	back(1, 0, 0);
	printf("%lld\n", ans);
	return 0;
}