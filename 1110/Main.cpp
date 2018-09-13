#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a = n / 10;
	int b = n % 10;
	int temp = b * 10 + (a + b) % 10;
	int cnt = 0;
	while (1) {
		cnt++;
		if (temp == n)break;
//		printf("%d\n",temp);
		a = temp / 10;
		b = temp % 10;
		temp = b * 10 + (a + b) % 10;
	}
	printf("%d\n", cnt);
	return 0;
}