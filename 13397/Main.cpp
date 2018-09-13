#include<stdio.h>

int n, m;
int inp[5010];
int tot = 0;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
		tot += inp[i];
	}
	int l = 0;
	int r = tot;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 1;
		int tl = inp[1];
		int tr = inp[1];
		for (int i = 2; i <= n; i++) {
			if (tl > inp[i])tl = inp[i];
			if (tr < inp[i])tr = inp[i];
			if (tr - tl > mid) {
				cnt++;
				tl = inp[i];
				tr = inp[i];
			}
		}
		if (cnt > m)l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}