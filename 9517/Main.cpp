#include<stdio.h>

int main() {
	int k, n;
	bool flag = false;
	scanf("%d %d", &k, &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int a = 0;
		char t[10] = { 0 };
		scanf("%d %s", &a, t);
		if (sum + a <= 210) {
			sum += a;
		}
		else {
			if (flag == false) {
				printf("%d\n", k);
				flag = true;
			}
		}
		if (t[0] == 'T') {
			k++;
			if (k == 9)k = 1;
		}
	}
	if (flag == false)printf("%d\n", k);
	return 0;
}