#include<stdio.h>
#include<string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char str[220] = { 0 };
		scanf("%s", str);
		int i = 0;
		int len = strlen(str);
		bool flag = true;
		while (i < len) {
			if (str[i] == '1') {
				if (str[i + 1] != '0' || str[i + 2] != '0') {
					flag = false;
//					printf("%d\n", i);
					break;
				}
				i += 2;
				while (1) {
					if (str[i] == '0')i++;
					else if (str[i] == 0) {
						flag = false;
//						printf("%d\n", i);
						break;
					}
					else {
						while (1) {
							if (str[i] == '1')i++;
							else break;
						}
						break;
					}
				}
			}
			else if (str[i] == '0') {
				if (str[i + 1] == '1') {
					i+=2;
				}
				else {
					if (i < 2 || str[i - 2] != '1') {
						flag = false;
//						printf("%d\n", i);
						break;
					}
					i--;
				}
			}
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}