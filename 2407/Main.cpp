#include<stdio.h>
#include<limits.h>
unsigned long long BIG = 10000000000000000;
bool table[110] = { 0 };

struct pos {
	long long a, b;
};

pos pas[110][110];

int main() {
	int n, r;
	scanf("%d %d", &n, &r);
	long long ans = 1;
	pas[0][0].a = 1;
	for (int i = 1; i <= n; i++) {
		pas[i][0].a = 1;
		for (int j = 1; j <= i; j++) {
			pas[i][j].b = pas[i - 1][j - 1].b + pas[i - 1][j].b + (pas[i - 1][j - 1].a + pas[i - 1][j].a) / BIG;
			pas[i][j].a = (pas[i - 1][j - 1].a + pas[i - 1][j].a) % BIG;
		}
	}
	BIG /= 10;
	if (pas[n][r].b) {
		printf("%lld", pas[n][r].b);
		while (BIG > pas[n][r].a) {
			BIG /= 10;
			printf("0");
		}
	}
	printf("%lld\n", pas[n][r].a);
	return 0;
}