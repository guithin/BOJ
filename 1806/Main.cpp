#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll inp[100010];

int main() {
	ll n, s;
	scanf("%lld %lld", &n, &s);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
	}
	ll r = 1, l = 1;
	ll sum = 0;
	ll ans = 1234567890;
	while(1) {
		if (r > n + 1)break;
		if (sum < s) {
			sum += inp[r]; r++;
		}
		else if (sum >= s) {
			ans = min(ans, r - l);
			sum -= inp[l]; l++;
		}
	}
	printf("%lld\n", ans == 1234567890 ? 0 : ans);
	return 0;
}