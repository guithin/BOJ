#include<stdio.h>

typedef long long ll;

ll a, b, c;
ll ans = 1;

long long qwer(long long cur) {
	if (!cur)return 1;
	if (cur == 1)return a % c;
	long long asdf = qwer(cur / 2) % c;
	if (cur % 2)return (((asdf*asdf) % c)*a) % c;
	else return (asdf*asdf) % c;
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", qwer(b));
	return 0;
}