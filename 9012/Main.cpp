#include<stdio.h>

int main() {
	int t;
	scanf("%d ", &t);
	while (t--) {
		char c;
		int open = 0;
		while ('\n' != (c = getchar())) {
			if (c == '(')open++;
			else if (--open < 0)open = 99;
		}
		printf("%s\n", open ? "NO" : "YES");
	}
	return 0;
}