#include<stdio.h>

int gcd(int a, int b) {
	if (a%b == 0)return b;
	return gcd(b, a%b);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n % m==0) {
		printf("0\n");
		return 0;
	}
	n %= m;
	int g = gcd(n, m);
//	printf("%d %d\n", n, m);
	int cnt = 0;
	int souse = 0;
	int ed = 0;
	int so = 0;
	while(1) {
		int use = n;
//		printf("%d %d %d ", so, souse, use);
		if (so > use) {
//			printf("plus");
			cnt++;
			so -= use;
		}
		else if (so == use) {
			so -= use;
		}
		else {
			souse++;
			so += m;
		}
//		printf("\n");
		if (souse > n)break;
	}
	printf("%d\n", cnt);
	return 0;
}