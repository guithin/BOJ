#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct pos {
	int a, b;
};

pos inp[110];

int main() {
	int n, l, k;
	int ans = 0;
	scanf("%d %d %d", &n, &l, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inp[i].a, &inp[i].b);
		if (inp[i].b <= l && k) {
			k--;
			ans += 100;
			inp[i].a = inp[i].b = 100000;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (inp[i].a <= l && k) {
			k--;
			ans += 40;
			inp[i].a = inp[i].b = 100000;
		}
	}
	printf("%d\n", ans);
	return 0;
}