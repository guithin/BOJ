#include<stdio.h>
#include<string.h>

int main() {
	char n[333350] = {0};
	scanf("%s", n);
	int len = strlen(n);
	bool flag = false;
	if (n[0] == '0') {
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < len; i++) {
		n[i] -= '0';
		for (int j = 4; j >= 1; j/=2) {
			if (n[i] / j == 1) {
				printf("1");
				flag = true;
				n[i] -= j;
			}
			else {
				if (flag == false)continue;
				printf("0");
			}
		}
	}
	printf("\n");
	return 0;
}