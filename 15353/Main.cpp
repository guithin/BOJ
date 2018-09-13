#include<stdio.h>
#include<string.h>

int main() {
	char a[10010] = {};
	char b[10010] = {};
	int ans[10010] = {};
	scanf("%s %s", a, b);
	int la = strlen(a);
	int lb = strlen(b);
	for (int i = la - 1, j = 10001; i >= 0; i--, j--) {
		a[j] = a[i] - 48;
		a[i] = 0;
	}
	for (int i = lb - 1, j = 10001; i >= 0; i--, j--) {
		b[j] = b[i] - 48;
		b[i] = 0;
	}
	for (int i = 10001; i >= 0; i--) {
		ans[i] = (a[i] + b[i]) % 10;
		if ((a[i] + b[i]) / 10) {
			a[i - 1]++;
		}
	}
	bool flag = false;
	for (int i = 0; i <= 10001; i++) {
		if (!ans[i] && !flag)continue;
		flag = true;
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}