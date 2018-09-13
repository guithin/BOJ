#include<stdio.h>
#include<algorithm>

int inpn[15] = { 0 };
int inpm[15] = { 0 };
int dp[500] = { 0 };

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)scanf("%d", inpn + i);
	std::sort(inpn + 1, inpn + 1 + n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 360; j++) {
			if (!dp[j])continue;
			for (int k = 0; inpn[i] * k + j <= 3600; k++) {
				dp[(j + inpn[i] * k)%360] = 1;
			}
			for (int k = 0; j - inpn[i] * k >= 0; k++) {
				dp[j - inpn[i] * k] = 1;
			}
		}
	}
/*	for (int i = 0; i <= 360; i++) {
		if (dp[i])printf("%d\n", i);
	}*/
	for (int i = 1; i <= m; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%s\n", dp[temp] ? "YES" : "NO");
	}
	return 0;
}