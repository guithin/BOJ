#include<stdio.h>

int input[110] = { 0 };
int dp[10010] = { 0 };
bool check[10010] = { 0 };
int n, now;

int dynamic(int k) {
	if (check[k] == true)return dp[k];
	check[k] = true;
	if (k == 0)return 0;
	int temp = 10000000;
	for (int i = n; i >= 1; i--) {
		if (k - input[i] < 0)continue;
		if (dynamic(k - input[i]) + 1 < temp)
			temp = dynamic(k - input[i]) + 1;
	}
	dp[k] = temp;
	return dp[k];
}

int main() {
	scanf("%d %d", &n, &now);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	if (dynamic(now) == 10000000)printf("-1\n");
	else printf("%d\n", dynamic(now));
	return 0;
}