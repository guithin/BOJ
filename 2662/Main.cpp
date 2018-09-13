#include <bits/stdc++.h>
using namespace std;
int N, M, a[301], b[301][21], dp[21][301], chs[21][301];

int func(int cur, int sum){
	if(cur > M)	return 0;
	int &ret = dp[cur][sum];
	if(ret != -1)	return ret;
	for(int i = 0; i <= N; i++)
		if(sum + a[i] <= N){
			int val = func(cur + 1, sum + a[i]) + b[i][cur];
			if(val > ret){
				ret = val;
				chs[cur][sum] = a[i];
			}
		}
	return ret;
}

void func2(int cur, int sum){
	if(cur > M)	return;
	printf("%d ", chs[cur][sum]);
	func2(cur + 1, sum + chs[cur][sum]);
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++){
		scanf("%d", a + i);
		for(int j = 1; j <= M; j++)
			scanf("%d", &b[i][j]);
	}
	int ans = func(1, 0);
	printf("%d\n", ans);
	func2(1, 0);
	puts("");
	return 0;
}