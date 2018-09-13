#include<stdio.h>

char str[100010] = { 0 };

int main() {
	scanf("%s", str);
	int open = 0;
	long long sum = 0;
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] == '(')open++;
		if (str[i] == ')') {
			open--;
			sum += open;
			if (open==0&&str[i-1]==')') {
				sum++;
			}
			else if (open != 0 && str[i - 1] == ')') {
				sum -= open - 1;
			}
		}
	}
	printf("%lld\n", sum);
	return 0;
}