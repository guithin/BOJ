#include<stdio.h>
#include<string.h>

int main() {
	int t;
	for (scanf("%d", &t); t; t--) {
		char str[30] = { 0 };
		scanf("%s", str);
		int len = strlen(str);
		if (len % 2) {
			for (int i = 0; i < len; i += 2) {
				printf("%c", str[i]);
			}
			for (int i = 1; i < len; i += 2) {
				printf("%c", str[i]);
			}
			printf("\n");
			for (int i = 1; i < len; i += 2) {
				printf("%c", str[i]);
			}
			for (int i = 0; i < len; i += 2) {
				printf("%c", str[i]);
			}
			printf("\n");
		}
		else {
			for (int i = 0; i < len; i += 2) {
				printf("%c", str[i]);
			}
			printf("\n");
			for (int i = 1; i < len; i += 2) {
				printf("%c", str[i]);
			}
			printf("\n");
		}
	}
	return 0;
}