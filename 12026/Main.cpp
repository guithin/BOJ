#include<stdio.h>
#include<memory.h>

int n;
int dp[1010] = { 0 };
char str[1010] = { 0 };

int main() {
	scanf("%d %s", &n, str);
	memset(dp, 40, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (str[i] == 'B'&&str[j] == 'O')
				if (dp[j] > dp[i] + (j - i)*(j - i))
					dp[j] = dp[i] + (j - i)*(j - i);
			if (str[i] == 'O'&&str[j] == 'J')
				if (dp[j] > dp[i] + (j - i)*(j - i))
					dp[j] = dp[i] + (j - i)*(j - i);
			if (str[i] == 'J'&&str[j] == 'B')
				if (dp[j] > dp[i] + (j - i)*(j - i))
					dp[j] = dp[i] + (j - i)*(j - i);
		}
	}
	if (dp[1009] == dp[n - 1])printf("-1\n");
	else printf("%d\n", dp[n - 1]);
	return 0;
}