#include<stdio.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;

const ll mod = 1000000007;
ll n;
ll inp[300010];
ll mem[300010];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", inp + i);
	}
	sort(inp + 1, inp + 1 + n);
	mem[1] = inp[1];
	unsigned long long temp = 2;
	ll ans = 0;
	for (ll i = 2; i <= n; i++) {
		ans += (inp[i] * ((temp - 1 + mod) % mod) + mod - mem[i - 1]) % mod;
		ans %= mod;
		mem[i] = (mem[i - 1] * 2 + inp[i]) % mod;
		temp *= 2;
		temp %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}