#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int o = b / 2;
	int temp = a;
	int m = b & 1;
	if (o && m) {
		printf("ERROR\n");
		return 0;
	}
	int ans = 0;
	if (m)a *= -1;
	a -= o;
	while (0 < a) {
		ans++;
		a -= o;
		if (temp <= a) {
			printf("INFINITE\n");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}