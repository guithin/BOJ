#include<stdio.h>

int inp[10010] = { 0 };
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", inp + i);
	int pi = 1;
	int pj = 1;
	int nowsum = inp[1];
	int cnt = 0;
	while (1) {
		if (pi == n + 1 && pj == n + 1)break;
		if (nowsum < m) {
			if (pj > n)break;
			nowsum += inp[pj + 1];
			pj++;
		}
		if (nowsum == m) {
			cnt++;
			nowsum -= inp[pi];
			pi++;
		}
		if (nowsum > m) {
			nowsum -= inp[pi];
			pi++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}