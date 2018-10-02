#include<bits/stdc++.h>
using namespace std;

int main() {
	char c = getchar();
	char d = getchar();
	int a;
	if (c == 'A')c = 4;
	else if (c == 'B')c = 3;
	else if (c == 'C')c = 2;
	else if (c == 'D')c = 1;
	else c = 0;
	if (!c) {
		printf("0.0\n"); return 0;
	}
	if (c&&d == '-')c--;
	printf("%d.%c\n", c, d == '0' ? '0' : (d == '+' ? '3' : '7'));
	return 0;
}