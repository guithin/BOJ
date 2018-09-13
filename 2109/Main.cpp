#include<stdio.h>
#include<algorithm>

struct pos {
	int day, money;
	pos() {};
	pos(int a, int b) {
		day = a;
		money = b;
	}
	bool operator<(const pos&io)const {
		return day < io.day;
	}
};

pos inp[10010];
int ans[10010] = { 0 };
int dp[10010] = { 0 };
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &inp[i].money, &inp[i].day);
	}
	std::sort(inp + 1, inp + 1 + n);

	ans[0] = 1000000;
	for (int i = 1; i <= n; i++) {
		int num = 0;
		for (int j = 1; j <= inp[i].day;j++) {
			if (ans[num] > ans[j])num = j;
		}
		if (num&&ans[num] < inp[i].money)
			ans[num] = inp[i].money;
	}

	int temp = 0;
	for (int i = 1; i <= 10000; i++) {
		temp += ans[i];
	}
/*	for (int i = 1; i <= 20; i++) {
		printf("%d ", ans[i]);
	}*/
	printf("%d\n", temp);
	return 0;
}