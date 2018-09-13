#include<stdio.h>

int chk[20000010];

void getint(int &x) {
	x = 0;
	bool m = false;
	bool flag = false;
	while (1) {
		char c = getchar();
		if (c == '-') {
			m = true; continue;
		}
		if (c<'0' || c>'9') {
			if (flag)
				break;
			else
				continue;
		}
		x *= 10; x += c - '0';
		flag = true;
	}
	if (m)x *= -1;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp; getint(temp);
		chk[temp + 10000000]++;
	}
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int temp; getint(temp);
		printf("%d\n", chk[temp + 10000000]);
	}
	return 0;
}