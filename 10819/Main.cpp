#include<bits/stdc++.h>
using namespace std;

int n;
int inp[10];
int chk[10];
int ans;

void back(int now, int sum, int ed) {
	if (now == n + 1) {
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i])continue;
		chk[i] = 1;
		back(now + 1, sum + abs(ed - inp[i])*(now != 1), inp[i]);
		chk[i] = 0;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	back(1, 0, 0);
	printf("%d\n", ans);
	return 0;
}