#include<bits/stdc++.h>
using namespace std;

char str[100];

bool pri(int i, int j) {
	while (i&&j&&str[i] == str[j]) {
		i--; j--;
	}
	return str[i] > str[j];
}

int main() {
	scanf("%s", str);
	int a = 0, b = 0;
	int len = strlen(str);
	for (int i = 0; i < len - 2; i++) {
		if (pri(a, i))a = i;
	}
	for (int i = b = a + 1; i < len - 1; i++) {
		if (pri(b, i))b = i;
	}
	for (int i = a; i > -1; i--)printf("%c", str[i]);
	for (int j = b; j > a; j--)printf("%c", str[j]);
	for (int i = len - 1; i > b; i--)printf("%c", str[i]);
	printf("\n");
	return 0;
}