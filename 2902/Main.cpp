#include<stdio.h>

int main() {
	char str[110] = { 0 };
	scanf("%s", str);
	printf("%c", str[0]);
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '-')printf("%c", str[i + 1]);
	}
	printf("\n");
	return 0;
}