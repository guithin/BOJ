#include<stdio.h>

int A, B, n;


int main() {
	scanf("%d %d %d", &A, &B, &n);
	int mini = 1234567890;
	for (int i = 1; i <= n; i++) {
		int c, nn;
		scanf("%d %d", &c, &nn);
		bool flag = false;
		for (int j = 1; j <= nn; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == A)flag = true;
			if (temp == B&&flag) {
				if (mini > c)mini = c;
			}
		}
	}
	if (mini == 1234567890) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", mini);
	return 0;
}