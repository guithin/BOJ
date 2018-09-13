#include<stdio.h>

int main() {
	int n = 5;
	int cnt = 0;
	for(int t=1;t<=5;t++) {
		char str[20] = { 0 };
		bool flag = false;
		scanf("%s", str);
		for (int i = 0; str[i] != 0; i++) {
			if (str[i] == 'F'&&str[i + 1] == 'B'&&str[i + 2] == 'I') {
				cnt++;
				flag = true;
				printf("%d ", t);
				break;
			}
		}
	}
	if (!cnt) {
		printf("HE GOT AWAY!\n");
		return 0;
	}
	return 0;
}