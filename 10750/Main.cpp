#include<stdio.h>
#include<string.h>

char str[1000010] = { 0 };
char ans[1000010] = { 0 };
char pock[400] = { 0 };

int main() {
	scanf("%s", str);
	scanf("%s", pock);
	int c = 0;
	int last = strlen(pock) - 1;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		ans[c] = str[i];
		if (ans[c] == pock[last] && c >= last) {
			if (strncmp(ans + c - last, pock, last + 1) == 0) {
				for (int j = c - last; j <= c; j++) {
					ans[j] = 0;
				}
				c -= last + 1;
			}
		}
		c++;
	}
	printf("%s\n", ans);
	return 0;
}