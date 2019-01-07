#include<stdio.h>

int main() {
	char str[101];
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", str);
	while (m--) {
		char temp[1001]; scanf("%s", temp);
		int j = 0;
		bool flag = true;
		for (int i = 0; str[i]; i++) {
			while (temp[j] && temp[j] != str[i])j++;
			if (!temp[j]) {
				flag = false;
				break;
			}
			else j++;
		}
		printf("%s\n", flag ? "true" : "false");
	}
	return 0;
}