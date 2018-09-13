#include<stdio.h>

int dp[100010];

int getint() {
	char c;
	int ret = 0;
	bool flag = false;
	while (1) {
		c = getchar();
		if (c == '-') {
			flag = true;
			continue;
		}
		if (c == ' ' || c == '\n' || c == EOF)break;
		ret *= 10; ret += c - '0';
	}
	return ret;
}

int main() {
	int n = getint(), k = getint();
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + getint();
	}
	while (k--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[b] - dp[a - 1]);
	}
	return 0;
}