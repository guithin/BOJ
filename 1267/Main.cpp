#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		a += temp / 30 + 1;
		b += temp / 60 + 1;
	}
	a *= 10; b *= 15;
	if (a>b)
		printf("M %d\n", b);
    else if(a==b)
        printf("Y M %d", a);
	else
		printf("Y %d\n", a);
	return 0;
}