#include<stdio.h>
#include<string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		bool fllag = false;
		scanf("%d", &n);
		for (int i = 2; i <= 64; i++) {
			int temp = n;
			bool flag = true;
			char chk[10010] = { 0 };
			int idx = 0;
			while (temp != 0) {
				chk[idx] += temp%i;
				chk[idx] += '0';
				temp /= i;
				idx++;
			}
			int len = strlen(chk);
			for (int j = 0; j < len / 2; j++) {
				if (chk[j] != chk[len - j - 1]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				printf("1\n");
				fllag = true;
				break;
			}
		}
		if (fllag)continue;
		else printf("0\n");
	}
	return 0;
}