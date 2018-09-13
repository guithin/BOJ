#include<stdio.h>

int arr[30] = { 0 };
int cnt = 0;
bool check[30] = { 0 };
int n, s;

void back(int cur) {
	if (cur == n + 1) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (check[i])sum += arr[i];
		}
		if (sum == s)cnt++;
		return;
	}
	check[cur] = false;
	back(cur + 1);
	check[cur] = true;
	back(cur + 1);
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	back(1);
	if (s == 0)cnt--;
	printf("%d\n", cnt);
	return 0;
}