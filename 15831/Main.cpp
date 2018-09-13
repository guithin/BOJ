#include<stdio.h>

int n, b, w;
int inp[300010];

int main() {
	scanf("%d %d %d ", &n, &b, &w);
	for (int i = 1; i <= n; i++) {
		inp[i] = getchar() == 'W';
	}
	int l = 1, r = 1, wc = 0, bc = 0, ans = 0;
	while (r <= n) {
		if (inp[r])wc++;
		else bc++;
		r++;
		while (bc > b && l < r) {
			if (inp[l])wc--;
			else bc--;
			l++;
		}
		if (wc >= w&&ans < r - l)ans = r - l;
	}
	printf("%d\n", ans);
	return 0;
}