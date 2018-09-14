#include<bits/stdc++.h>
using namespace std;

int len;
int n;
int ans;
vector<int>vec;

void back(int cur, int flag, int num) {
	if (cur == len + 1) {
		vec.push_back(num);
		if (num > n) {
			printf("%d\n", ans);
			exit(0);
		}
		ans = max(ans, num);
		return;
	}
	if (!flag) {
		back(cur + 1, false, num);
	}
	back(cur + 1, true, num * 10 + 4);
	back(cur + 1, true, num * 10 + 7);
}

int main() {
	scanf("%d", &n);
	len = 7;
	back(1, false, 0);
	
	return 0;
}