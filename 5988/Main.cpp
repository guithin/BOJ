#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	scanf(" ");
	while (n--) {
		char ed;
		while (1) {
			char c = getchar();
			if (c == '\n' || c == -1) {
				printf("%s\n", ed & 1 ? "odd" : "even");
				break;
			}
			ed = c;
		}
	}
	return 0;
}