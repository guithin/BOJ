#include<stdio.h>
#include<algorithm>
using namespace std;

int inp[10010] = { 0 };
int dp[10010] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", inp + i);
	dp[1] = inp[1];
	dp[2] = inp[1] + inp[2];
    for(int i=3;i<=n;i++){
        dp[i]=max({dp[i-1], dp[i-2]+inp[i], dp[i-3]+inp[i]+inp[i-1]});
    }
	printf("%d\n", dp[n]);
	return 0;
}