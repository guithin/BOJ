#include<stdio.h>

int main() {
	int n; scanf("%d", &n);
	int arr[55], brr[55];
	for (int i = 1; i <= n; i++) {
		arr[i] = i + 1;
		brr[i] = i - 1;
	}
	arr[n] = 1;
	brr[1] = n;
	int m; scanf("%d", &m);
	int f = 1;
	int ans = 0;
	while (m--) {
		int t; scanf("%d", &t);
		int nf = f;
		int idx = 0;
		while (nf != t) {
			nf = arr[nf];
			idx++;
		}
		int temp = arr[nf];
		arr[brr[nf]] = temp;
		brr[temp] = brr[nf];
		f = arr[nf];
		if (n - idx < idx)ans += n - idx;
		else ans += idx;
		n--;
	}
	printf("%d\n", ans);
	return 0;
}