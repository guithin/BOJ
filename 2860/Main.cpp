#include<stdio.h>
#include<string.h>
typedef long long ll;

ll sqr(ll x, ll y) {
	ll R = 1;
	for (ll i = 1; i <= y; i++) {
		R *= x;
	}
	return R;
}

ll gcd(ll a, ll b) {
	return (a%b) ? gcd(b, a%b) : b;
}

int main() {
	ll jeongsu;
	char temp[100] = { 0 };
	scanf("%lld.%s", &jeongsu, temp);
	ll len = strlen(temp);
	ll mo = sqr(10, len);
	ll sosu = jeongsu;
	for (ll i = 0; i < len; i++) {
		sosu *= 10;
		sosu += temp[i] - '0';
	}
	ll nanu = gcd(mo, sosu);
	mo /= nanu;
	sosu /= nanu;
//	printf("%lld / %lld\n", sosu, mo);
	ll integer[10] = { 0 };
	ll temp2 = mo;
	ll temp3 = sosu;
	ll idx = sosu / mo;
	integer[idx] = mo;
	sosu %= mo;
	integer[idx] -= sosu;
	integer[idx + 1] = sosu;
	for (ll i = 1; i <= 5; i++) {
		printf("%lld ", integer[i]);
	}
	printf("\n");
	return 0;
}