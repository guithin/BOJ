#include<stdio.h>
#include<string.h>

int main() {
	while (1) {
		char str[100000] = { 0 };
		int idx = 0;
		while (1) {
			char temp = getchar();
			if (temp == '\n' || temp == 0 || temp == EOF)break;
			str[idx] = temp;
			idx++;
		}
		if (strcmp(str, "END") == 0)return 0;
		for (int i = idx - 1; i >= 0; i--) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
}