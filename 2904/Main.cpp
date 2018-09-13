#include<stdio.h>
#include<algorithm>
#include<vector>

int sqr(int x, int y) {
	int R = 1;
	while (y--)R *= x;
	return R;
}

int n;
int inp[110];
int chk[1000010];
std::vector<int>vec;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", inp + i);
	for (int i = 1; i <= n; i++) {
		int temp = inp[i];
		while (temp != 1) {
			for (int j = 2; j <= temp; j++) {
				if (temp%j == 0) {
					chk[j]++;
					temp /= j;
					break;
				}
			}
		}
	}
	std::sort(inp + 1, inp + 1 + n);
	int ans = 1;
	for (int i = 2; i <= inp[n]; i++) {
		ans *= sqr(i, chk[i] / n);
		chk[i] /= n;
		if (chk[i])vec.push_back(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < vec.size(); j++) {
			int tmp = chk[vec[j]];
			while (tmp) {
				if (inp[i] % vec[j] == 0) {
					inp[i] /= vec[j];
					tmp--;
				}
				else
					break;
			}
			cnt += tmp;
		}
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}