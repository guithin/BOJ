#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	ll c = a / b;
	ll d = a % b;
	ll ans = 1;
	while (d--) {
		ans *= c + 1; b--;
	}
	while (b--)ans *= c;
	printf("%lld\n", ans);
	return 0;
}