#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ans = 0;
	while (c != b) {
		++b >>= 1; ++c >>= 1; ans++;
	}
	printf("%d\n", ans);
	return 0;
}