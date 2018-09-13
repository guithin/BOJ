#include<stdio.h>
#include<string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char str[110] = { 0 };
		int i = 0;
		scanf("\n");
		while (1) {
			str[i] = getchar();
			if (str[i] == 0 || str[i] == '\0' || str[i] == '\n' || str[i] == EOF)break;
			i++;
		}
		printf("god");
		bool flag = false;
		for (int j = 0; str[j] != 0; j++) {
			if (str[j] == ' ') {
				if (flag == false)flag = true;
				continue;
			}
			if (flag)printf("%c", str[j]);
		}
	}
	return 0;
}