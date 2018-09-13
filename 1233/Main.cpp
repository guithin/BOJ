#include<stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ed = 0;
	for (int i = 3; i <= a + b + c; i++) {
		int now = 0;
		for (int j = 1; j <= a; j++) {
			for (int k = 1; k <= b; k++) {
				for (int l = 1; l <= c; l++) {
					if (j + k + l == i)now++;
				}
			}
		}
		if (now > ed)ed = now;
		else {
			printf("%d\n", now > ed ? i : i - 1);
			return 0;
		}
	}
	return 0;
}