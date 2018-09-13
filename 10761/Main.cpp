#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll inp[200][10];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		char a;
		ll b;
		scanf(" %c %lld", &a, &b);
		inp[a][((b % 7) + 7) % 7]++;
	}
	unsigned long long ans = 0;
	for (ll b = 0; b < 7; b++) {
		for (ll e = 0; e < 7; e++) {
			for (ll s = 0; s < 7; s++) {
				for (ll i = 0; i < 7; i++) {
					for (ll g = 0; g < 7; g++) {
						for (ll o = 0; o < 7; o++) {
							for (ll m = 0; m < 7; m++) {
								if (!((b + e + s + s + i + e) % 7) || !((g + o + e + s) % 7) || !((m + o + o) % 7)) {
									ll plus = inp['B'][b] * inp['E'][e] * inp['S'][s] * inp['I'][i] * inp['G'][g] * inp['O'][o] * inp['M'][m];
									ans += plus;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%llu\n", ans);
	return 0;
}