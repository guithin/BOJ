#include<stdio.h>
#include<algorithm>

int abb(int x) {
	return x > 0 ? x : -x;
}

int input[100000] = { 0 };
int idx = 0;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int len, n;
		scanf("%d %d", &len, &n);
		int f1, f2, b1, b2;
		int mini=10000000, maxi;
		for (int i = 0; i < n; i++) {
			scanf("%d", &input[i]);
		}
		std::sort(input, input + n);
		if (len - input[0] > input[n - 1])maxi = len - input[0];
		else maxi = input[n - 1];
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (abb((len / 2) - input[i]) < mini) {
				mini = abb((len / 2) - input[i]);
				j = i;
			}
		}
		printf("%d %d\n", ((len/2)-input[j])>0?input[j]:len-input[j], maxi);
	}
	return 0;
}