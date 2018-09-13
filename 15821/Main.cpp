#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n, k;
ll inp[100010];

int main() {
	scanf("%lld %lld", &n, &k);
	for (ll i = 1; i <= n; i++) {
		ll num, maxi = 0;
		scanf("%lld", &num);
		for (ll j = 1; j <= num; j++) {
			ll q, w;
			scanf("%lld %lld", &q, &w);
			if (maxi < q * q + w * w) {
				maxi = q * q + w * w;
			}
		}
		inp[i] = maxi;
	}
	sort(inp + 1, inp + 1 + n);
	printf("%lld.00\n", inp[k]);
	return 0;
}