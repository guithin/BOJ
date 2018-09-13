#include<stdio.h>

int n, m;
int input[110] = { 0 };
int ans = -100000;
int sum = 0;
bool check[110] = { 0 };


void back(int cur) {
	if (cur == 4) {
		if (sum <= m) {
			if (m-sum < m-ans) {
				ans = sum;
			}
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i] == true)continue;
		check[i] = true;
		sum += input[i];
		back(cur + 1);
		check[i] = false;
		sum -= input[i];
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	back(1);
	printf("%d\n", ans);
	return 0;
}