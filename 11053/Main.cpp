#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
int inp[1010];
int dp[1010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &inp[i]);
	}
	for (int i = 1; i <= n; i++) {
		int mini = 0;
		for (int j = 1; j < i; j++) {
			if (inp[i] > inp[j] && mini < dp[j]) {
				mini = dp[j];
			}
		}
		dp[i] = mini + 1;
	}
	printf("%d\n", *max_element(dp + 1, dp + 1 + n));
	return 0;
}