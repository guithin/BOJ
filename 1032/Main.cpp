#include<stdio.h>
#include<string.h>
//.==46, ?==63
char str[55][55] = { 0 };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%s", str[i]);
	int len = strlen(str[1]);
	for (int i = 0; i < len; i++) {
		bool flag = true;
		for (int j = 1; j < n; j++) {
			if (str[j][i] != str[j + 1][i]) {
				flag = false;
				break;
			}
		}
		if (flag)printf("%c", str[1][i]);
		else printf("?"); 
	}
	printf("\n");
	return 0;
}