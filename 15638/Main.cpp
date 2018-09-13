#include<stdio.h>

bool chk[1000010] = { 0 };

int main() {
	chk[0] = true;
	chk[1] = true;
	for (int i = 2; i <= 500000; i++) {
		if (chk[i])continue;
		for (int j = 2; i*j <= 1000000; j++) {
			chk[i*j] = true;
		}
	}
    int n;
    scanf("%d", &n);
    printf("%s\n", chk[n]?"No":"Yes");
	return 0;
}