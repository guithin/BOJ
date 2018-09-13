#include<stdio.h>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n;
ll inp[1000010];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
	}
	ll sum = 0;
	for (ll i = 1; i > 0; i <<= 1) {
		ll on = 0;
		ll off = 0;
		for (ll j = 1; j <= n; j++) {
			if (inp[j] & i)on++;
			else off++;
		}
		sum += on * off * i;
	}
	printf("%lld\n", sum);
	return 0;
}