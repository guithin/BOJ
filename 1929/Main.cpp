#include<stdio.h>

bool chk[1000010] = { 0 };

int main() {
	chk[0] = true;
	chk[1] = true;
	for (int i = 2; i <= 500000; i++) {
		if (chk[i])continue;
		for (int j = 2; i*j <= 1000000; j++) {
			chk[i*j] = true;
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	int cnt = 0;
	for (int i = a; i <= b; i++)
		if (!chk[i])printf("%d\n", i);
	return 0;
}