#include<stdio.h>

int main() {
	while (1) {
		int n;
		scanf("%d", &n);
		if (n < 0)return 0;
		int stack[1000] = { 0 };
		int stack2[1000] = { 0 };
		int idx2 = 0;
		int idx = 0;
		int sum = 0;
		for (int i = 1; i*i <= n; i++) {
			if (n%i == 0) {
				stack[idx] = i;
				idx++;
				sum += i;
				if (i != n / i) {
					stack2[idx2] = n / i;
					idx2++;
					sum += n / i;
				}
			}
		}
		if (sum == 2 * n) {
			printf("%d = ", n);
			for (int i = 0; i < idx; i++) {
				printf("%d + ", stack[i]);
			}
			for (int i = idx2 - 1; i > 0; i--) {
				printf("%d", stack2[i]);
				if (i != 1)printf(" + ");
			}
			printf("\n");
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}

	}
}
