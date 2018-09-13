#include<bits/stdc++.h>
using namespace std;

int main() {
	long long a;
	scanf("%lld", &a);
	long long ans = a & 1ll ? (a - 1ll) / 2ll * a : a / 2ll * (a - 1ll);
	printf("%lld\n", ans);
	return 0;
}