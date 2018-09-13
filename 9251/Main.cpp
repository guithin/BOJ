#include<stdio.h>
#include<string.h>
#include<algorithm>

int dp[1010][1010] = { 0 };

int main() {
	char str_a[1010] = { 0 };
	char str_b[1010] = { 0 };
	scanf("%s", str_a + 1);
	scanf("%s", str_b + 1);
	int len_a = strlen(str_a + 1);
	int len_b = strlen(str_b + 1);
	for (int i = 1; i <= len_a; i++) {
		for (int j = 1; j <= len_b; j++) {
			if (str_a[i] == str_b[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
//				if (dp[i][j] > i || dp[i][j] > j)dp[i][j] = std::min(i, j);
			}
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
/*	for (int i = 0; i <= len_b; i++) {
		for (int j = 0; j <= len_a; j++) {
			printf("%d ", dp[j][i]);
		}
		printf("\n");
	}*/
	printf("%d\n", dp[len_a][len_b]);
	return 0;
}