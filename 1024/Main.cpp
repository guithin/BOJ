#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
	ll n, m; scanf("%lld %lld", &n, &m);
	ll arr[101] = { 0 };
	for (ll i = 1; i <= 100; i++) {
		arr[i] = arr[i - 1] + i - 1;
	}
	for (ll i = m; i <= 100; i++) {
		if (!((n - arr[i]) % i) && (n - arr[i]) / i >= 0) {
			for (ll j = 0; j < i; j++) {
				printf("%lld ", (n - arr[i]) / i + j);
			}
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}