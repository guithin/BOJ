#include<stdio.h>
#include<vector>
typedef long long ll;

ll n, t;
std::vector<ll>vec;

int main() {
	scanf("%lld %lld", &n, &t);
	for (ll i = 1; i <= n; i++) {
		ll a, b;
		scanf("%lld %lld", &a, &b);
		b = a + b * t;
		if (vec.empty() || vec[vec.size() - 1] >= b)
			vec.push_back(b);
		else {
			ll l = 0;
			ll r = vec.size() - 1;
			while (l <= r) {
				ll mid = (l + r) / 2;
				if (vec[mid] < b) {
					r = mid - 1;
				}
				else if (vec[mid] >= b) {
					l = mid + 1;
				}
			}
			vec[l] = b;
		}
	}
	printf("%lld\n", (ll)vec.size());
	return 0;
}