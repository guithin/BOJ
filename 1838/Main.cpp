#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int inp[500010];
int tmp[500010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
		tmp[i] = inp[i];
	}
	sort(tmp + 1, tmp + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i - (lower_bound(tmp + 1, tmp + 1 + n, inp[i]) - tmp) > ans)
			ans = i - (lower_bound(tmp + 1, tmp + 1 + n, inp[i]) - tmp);
	}
	printf("%d\n", ans);
	return 0;
}