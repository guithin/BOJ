#include<stdio.h>

char str[1000010];
int check[100];

int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] >= 'a'&&str[i] <= 'z') {
			check[str[i] - 'a' + 1]++;
		}
		else
			check[str[i] - 'A' + 1]++;
	}
	int maxi = 0;
	int now = 0;
	for (int i = 1; i <= 26; i++) {
		if (check[i] > maxi) {
			maxi = check[i];
			now = i;
		}
		else if (check[i] == maxi) {
			now = 12345;
		}
	}
	if (now == 12345)printf("?\n");
	else printf("%c\n", now - 1 + 'A');
	return 0;
}