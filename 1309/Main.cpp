#include<stdio.h>
#include<iostream>
#include<string>

const int mod = 9901;

using namespace std;
int dp[2][100010];

int main() {
	int n;
	scanf("%d", &n);
	dp[0][1] = 3;
	dp[1][1] = 2;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = (dp[0][i - 1] * 3 - dp[1][i - 1]) % mod;
		dp[1][i] = (dp[0][i - 1] * 2 - dp[1][i - 1]) % mod;
	}
/*
	for (int i = 1; i <= n; i++) {
		cout << dp[0][i] << ' ';
	}
	cout << endl;
*/
	while (dp[0][n] < 0)dp[0][n] += mod;
	cout << dp[0][n] << '\n';
	return 0;
}