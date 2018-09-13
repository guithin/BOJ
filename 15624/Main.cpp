#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (!n) {
		printf("0\n");
		return 0;
	}
	n--;
	int a = 0, b = 1;
	while (n--) {
		int temp = b;
		b += a;
		if (b > 1000000007)
			b -= 1000000007;
		a = temp;
	}
	printf("%d\n", b);
	return 0;
}