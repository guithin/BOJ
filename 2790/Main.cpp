#include<stdio.h>
#include<algorithm>

int inp[300010] = { 0 };
int tem[300010] = { 0 };
int n;

int main() {
//	freopen("f7.in.5.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	std::sort(inp + 1, inp + 1 + n);
	int maxi = -1;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		tem[i] = inp[i] + n - i + 1;
		if (maxi < inp[i] + n - i + 1) {
			maxi = inp[i] + n - i + 1;
			idx = i;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (inp[i] + n >= maxi)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}