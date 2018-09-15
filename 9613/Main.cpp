#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a%b) : b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int arr[110];
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", arr + i);
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}