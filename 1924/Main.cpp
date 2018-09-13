#include<stdio.h>

int main() {
	int t=1;
	char yo[10][10] = { { 'S','U','N' },{ 'M','O','N' },{ 'T','U','E' },{ 'W','E','D' },{ 'T','H','U' },{ 'F','R','I' },{ 'S','A','T' } };
	while (t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int first = 1234;
		if (x == 1)first = 4;
		else if (x == 2)first = 0;
		else if (x == 3)first = 0;
		else if (x == 4)first = 3;
		else if (x == 5)first = 5;
		else if (x == 6)first = 1;
		else if (x == 7)first = 3;
		else if (x == 8)first = 6;
		else if (x == 9)first = 2;
		else if (x == 10)first = 4;
		else if (x == 11)first = 0;
		else if (x == 12)first = 2;
		first += y;
		first += 3;
		first %= 7;
		printf("%s\n", yo[first]);
	}
	return 0;
}