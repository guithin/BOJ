#include<stdio.h>
#include<algorithm>

int main() {
	int a[10] = { 0 };
	int b[5] = { 0 };
	scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &b[0], &b[1]);
	std::sort(a, a + 3);
	std::sort(b, b + 2);
	printf("%d\n", a[0] + b[0]-50);
	return 0;
}