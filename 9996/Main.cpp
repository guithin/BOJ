#include<stdio.h>
#include<string.h>

char check[110];

int main() {
	int n;
	int mode = -1;
	scanf("%d", &n);
	scanf("%s", check);
	int chklen = strlen(check);
	if (check[0] == '*')mode = 1;
	else if (check[chklen - 1] == '*')mode = 2;
	else mode = 3;
	int a1;
	for (int i = 0; check[i] != 0; i++) {
		if (check[i] == '*')
			a1 = i;
	}
	while (n--) {
		char input[110] = { 0 };
		scanf("%s", input);
		int len = strlen(input);
		if (len < chklen - 1) {
			printf("NE\n");
			continue;
		}
		if (strncmp(check, input, a1) == 0 && strncmp(check + a1 +1, input + len + 1 - (chklen - a1), chklen - a1 - 1)==0) {
			printf("DA\n");
			continue;
		}
	printf("NE\n");
	}
	return 0;
}