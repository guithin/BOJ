#include<stdio.h>
#include<algorithm>

int input1[100010] = { 0 };
int input2[100010] = { 0 };
int ans[500010] = { 0 };

int main() {
	int n, h;
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n / 2; i++)
		scanf("%d %d", input1 + i, input2 + i);
	std::sort(input1 + 1, input1 + 1 + n / 2);
	std::sort(input2 + 1, input2 + 1 + n / 2);

	int idx = 1;
	for (int i = 1; i <= h; i++) {
		while (input1[idx] < i && idx <= n / 2)idx++;
		ans[i] += (n / 2) - idx + 1;
	}
	idx = 1;
	for (int i = 1; i <= h; i++) {
		while (input2[idx] < i && idx <= n / 2)idx++;
		ans[h - i + 1] += (n / 2) - idx + 1;
	}
	int mini = 987654321;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (mini > ans[i]) {
			mini = ans[i];
			cnt = 1;
		}
		else if (mini == ans[i])cnt++;
	}
	printf("%d %d\n", mini, cnt);
}