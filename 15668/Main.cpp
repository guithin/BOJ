#include<bits/stdc++.h>
using namespace std;

int n;
int pick[11];
int chk[11];

void back(int cur) {
	if (cur == 11) {
		for (int i = 0; i <= 10; i++) {
			for (int j = 0; j <= min(i, 10 - i); j++) {
				int a = 0, b = 0;
				for (int k = 0; k <= i; k++) {
					a *= 10; a += pick[k];
				}
				for (int k = 0; k <= j; k++) {
					b *= 10; b += pick[k + i + 1];
				}
				if (a + b == n && a && b) {
					printf("%d + %d\n", a, b);
					exit(0);
				}
			}
		}
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			pick[cur] = i;
			back(cur + 1);
			chk[i] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);
	back(1);
	printf("-1\n");
	return 0;
}