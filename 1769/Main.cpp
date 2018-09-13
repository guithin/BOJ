#include<stdio.h>
#include<string.h>

char str[1000010] = { 0 };

int main() {
	scanf("%s", str);
	if (strlen(str) == 1) {
		printf("0\n");

		if ((str[0] - 48) % 3 == 0&&str[0]!=48)printf("YES\n");
		else printf("NO\n");
		return 0;
	}
	int cnt = 1;
	int temp = 0;
	for (int i = 0; str[i] != 0; i++) {
		temp += str[i] - 48;
	}
	while (1) {
		if (temp < 10) {
			break;
		}
		int temp2 = 0;
		while (temp != 0) {
			temp2 += temp % 10;
			temp /= 10;
		}
		temp = temp2;
		cnt++;
	}
	printf("%d\n", cnt);
	if (temp % 3 == 0)printf("YES\n");
	else printf("NO\n");
	return 0;
}