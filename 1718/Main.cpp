#include<stdio.h>
#include<string.h>

char inp[30010];
char key[30010];

int main() {
	int i = 0;
	while (1) {
		char c = getchar();
		if (c == '\n')break;
		inp[i++] = c;
	}
	scanf("%s", key);
	int len = strlen(key);
	for (i = 0; inp[i]; i++) {
		if (inp[i] == ' ') {
			printf(" ");
			continue;
		}
		printf("%c", (inp[i] - key[i%len] + 259) % 26 + 'a');
	}
	return 0;
}