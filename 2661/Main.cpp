#include<stdio.h>
#include<string.h>

bool ans = false;

void back(int cur, int n, char*arr) {
	if (ans)return;
	if (cur == n + 1) {
		for (int i = 1; i <= n; i++)printf("%d", arr[i]);
		printf("\n");
		ans = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		bool flag = true;
		arr[cur] = i;
		for (int j = 1; j <= cur / 2; j++) {
			if (!strncmp(arr + 1 + cur - j, arr + 1 + cur - 2 * j, j)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			back(cur + 1, n, arr);
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	char arr[100] = { 0 };
	back(1, n, arr);
	return 0;
}