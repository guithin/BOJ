#include<stdio.h>

struct pos {
	int q, w;
	pos() {};
	pos(int a, int b) {
		q = a;
		w = b;
	}
};

pos dp[1000010];
int sosu[1000010] = { 1,1 };
int sooo[100000];
int idx = 0;

int main() {
	for (int i = 2; i <= 1000000; i++) {
		if (sosu[i])continue;
		for (int j = 2; i*j <= 1000000; j++) {
			sosu[i*j] = true;
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		if (sosu[i] == 0) {
			sooo[idx] = i;
			idx++;
		}
	}
	for (int i = 6; i <= 1000000; i+=2) {
		for (int j = 0; j < idx; j++) {
			if (sosu[i - sooo[j]] == 0) {
				dp[i] = pos(sooo[j], i - sooo[j]);
				break;
			}
		}
	}
	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0)return 0;
//		if (dp[n].q == 0)printf("Goldbach's conjecture is wrong.\n");
		else printf("%d = %d + %d\n", n, dp[n].q, dp[n].w);
	}
	return 0;
}