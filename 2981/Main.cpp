#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
	return a % b ? gcd(b, a%b) : b;
}

int inp[110];
vector<int>bk;

int main() {
	int n;
	scanf("%d", &n);
	int gcd_int = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	sort(inp + 1, inp + 1 + n);
	gcd_int = inp[2] - inp[1];
	for (int i = 2; i < n; i++) {
		gcd_int = gcd(gcd_int, inp[i + 1] - inp[i]);
	}
	for (int i = 2; i*i <= gcd_int; i++) {
		if (!(gcd_int%i)) {
			printf("%d ", i);
			if (i == gcd_int / i)continue;
			bk.push_back(gcd_int / i);
		}
	}
	for (int i = bk.size() - 1; i >= 0; i--) {
		printf("%d ", bk[i]);
	}
	printf("%d", gcd_int);
	printf("\n");
	return 0;
}