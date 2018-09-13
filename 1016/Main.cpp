#include<stdio.h>
typedef long long ll;

bool chk[1000010];
bool inp[10000010];

int main() {
	chk[0] = chk[1] = true;
	for (ll i = 2; i <= 1000000; i++) {
		if (chk[i])continue;
		for (ll j = 2; i*j <= 1000000; j++) {
			chk[i*j] = true;
		}
	}
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll sub = b - a;
	for (ll i = 2; i*i <= b; i++) {
		if (!chk[i]) {
			for (ll j = a/(i*i); j*i*i <= b; j++) {
				if (j*i*i < a)continue;
				inp[j*i*i - a] = 1;
			}
		}
	}
	ll cnt = 0;
	for (ll i = 0; i <= sub; i++) {
		if (!inp[i])cnt++;
	}
	printf("%lld\n", cnt);
	return 0;
}