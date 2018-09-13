#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int temp = 2;
	for (int i = 1; i <= n; i++) {
		temp = 2 * temp - 1;
	}
	printf("%d\n", temp*temp);
	return 0;
}