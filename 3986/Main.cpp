#include<stdio.h>

int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	while (n--) {
		char str[100010] = { 0 };
		char stack[100010] = { 0 };
		int idx = 0;
		int aopen = 0;
		int bopen = 0;
		scanf("%s", str);
		for (int i = 0; str[i] != 0; i++) {
			if (str[i] == 'A') {
				if (stack[idx - 1]=='A') {
					aopen--;
					idx--;
					continue;
				}
				aopen++;
				stack[idx] = 'A';
				idx++;
			}
			else if (str[i] == 'B') {
				if (stack[idx - 1] == 'B') {
					bopen--;
					idx--;
					continue;
				}
				bopen++;
				stack[idx] = 'B';
				idx++;
			}
		}
		if (aopen == 0 && bopen == 0)cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}