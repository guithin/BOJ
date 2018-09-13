#include<stdio.h>
#include<memory.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n % 10) {
		printf("-1\n");
		return 0;
	}
	int cnt = 0;
	printf("%d ", n / 300); n %= 300;
	printf("%d ", n / 60); n %= 60;
	printf("%d\n", n / 10);
	return 0;
}