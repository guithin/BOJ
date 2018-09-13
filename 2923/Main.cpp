#include<stdio.h>

int asort[110] = { 0 };
int bsort[110] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int at[110] = { 0 };
		int bt[110] = { 0 };
		asort[a]++;
		bsort[b]++;
		int big = 0;
		for (int j = 1; j <= 101; j++) {
			at[j] = asort[j];
			bt[j] = bsort[j];
		}
		int idx = 100;
		for (int j = 1; j <= 100; j++) {
			while (1) {
				if (at[j] == 0)j++;
				if (bt[idx] == 0)idx--;
				if (at[j] != 0 && bt[idx] != 0)break;
				if (j > 100 || idx < 1)break;
			}
			if (j > 100 || idx < 1)break;
			if (at[j] > bt[idx]) {
				at[j] -= bt[idx];
				bt[idx] = 0;
				if (big < j + idx)big = j + idx;
				j--;
			}
			else if (at[j] < bt[idx]) {
				bt[idx] -= at[j];
				at[j] = 0;
				if (big < j + idx)big = j + idx;
//				idx--;
			}
			else {
				if (big < j + idx)big = j + idx;
				idx--;
			}
		}
		printf("%d\n", big);
	}
	return 0;
}