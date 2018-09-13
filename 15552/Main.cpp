#include<stdio.h>

int main() {
	char c;
	int t = 0;
	while (1) {
		c = getchar();
		if (c >= '0'&&c <= '9') {
			t *= 10; t += c - '0';
		}
		else if (t)break;
	}
	while (t--) {
		int a = 0, b = 0;
		while (1) {
			c = getchar();
			if (c >= '0'&&c <= '9') {
				a *= 10; a += c - '0';
			}
			else if (a)break;
		}

		while (1) {
			c = getchar();
			if (c >= '0'&&c <= '9') {
				b *= 10; b += c - '0';
			}
			else if (b)break;
		}

		printf("%d\n", a + b);
	}
	return 0;
}