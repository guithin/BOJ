#include<stdio.h>

int lv[50][50];

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	for (int i = 0; i <= 9; i++) {
		lv[i][1] = 1;
	}
	for (int i = 2; i <= 11; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = j-1; k >= 0; k--) {
				lv[j][i] += lv[k][i - 1];
			}
		}
	}
	lv[0][1] = 0;
/*	printf("\n");
	printf("\t");
	for (int i = 0; i <= 9; i++)
		printf("\t%d", i);
	printf("\n");
	for (int i = 1; i <= 11; i++) {

		printf("\t%d", i);
		for (int j = 0; j <= 9; j++) {
			printf("\t%d", lv[j][i]);
		}
		printf("\n");
	}*/
//	int t;
//	scanf("%d", &t);
//	while (t--) {
		int n;
		int nu = 0;
		scanf("%d", &n);
		if (n > 1022) {
			printf("-1\n");
			return 0;
		}
		long long num = 0;
		int mi = 0;
		bool flag = false;
		for (int i = 1; i <= 10; i++) {
			for (int j = 0; j <= 9; j++) {
				nu += lv[j][i];
				if (nu >= n) {
					mi = i;
					for (int k = 1; k <= i; k++) {
						num *= 10;
						num += j - k + 1;
					}
					flag = true;
					break;
				}
			}
			if (flag)break;
		}
		int len = mi;
		int qwer[15] = { 0 };
		long long temp = num;
		while (temp != 0) {
			qwer[mi] = temp % 10;
			temp /= 10;
			mi--;
		}
		for (int i = nu; i > n; i--) {
			for (int j = len; j >= 1; j--) {
				if (qwer[j] >= len-j+1) {
					qwer[j]--;
					for (int k = j+1; k <= len; k++) {
						qwer[k] = qwer[k - 1] - 1;
					}
					break;
				}
			}
		}
//		printf("%d ", n);
		for (int i = 1; i <= len; i++)
			printf("%d", qwer[i]);
		printf("\n");
//	}
	return 0;
}