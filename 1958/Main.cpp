#include<stdio.h>
#include<algorithm>
#include<string.h>

char dp[110][110][110] = { 0 };

int main() {
	char str1[110] = { 0 };
	char str2[110] = { 0 };
	char str3[110] = { 0 };
	scanf("%s %s %s", str1 + 1, str2 + 1, str3 + 1);
	int len1 = strlen(str1 + 1);
	int len2 = strlen(str2 + 1);
	int len3 = strlen(str3 + 1);
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			for (int k = 1; k <= len3; k++) {
				if (str1[i] == str2[j] && str1[i] == str3[k]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
					dp[i][j][k] = std::max(dp[i - 1][j][k], std::max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}
	printf("%d\n", dp[len1][len2][len3]);
	return 0;
}