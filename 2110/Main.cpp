#include<stdio.h>
#include<algorithm>
#include<limits.h>

int input[200010] = { 0 };

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++)
		scanf("%d", input + i);
	std::sort(input + 1, input + 1 + n);
	int l = 1;
	int r = INT_MAX;
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 1;
		int ed = input[1];
		for (int i = 1; i <= n; i++) {
			if (input[i] - ed >= mid) {
				ed = input[i];
				cnt++;
			}
		}
		if (cnt < c) {
			r = mid - 1;
		}
		else if (cnt >= c) {
			l = mid + 1;
		}
	}
	printf("%d\n", r);
//	printf("%d %d\n", l, r);
	return 0;
}