#include<stdio.h>

int main() {
	char str[20] = { 0 };
	int sum = 0;
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++) {
		if (str[i] >= 'A'&&str[i] <= 'C')
			sum += 3;
		else if (str[i] >= 'D'&&str[i] <= 'F')
			sum += 4;
		else if (str[i] >= 'G'&&str[i] <= 'I')
			sum += 5;
		else if (str[i] >= 'J'&&str[i] <= 'L')
			sum += 6;
		else if (str[i] >= 'M'&&str[i] <= 'O')
			sum += 7;
		else if (str[i] >= 'P'&&str[i] <= 'S')
			sum += 8;
		else if (str[i] >= 'T'&&str[i] <= 'V')
			sum += 9;
		else if (str[i] >= 'W'&&str[i] <= 'Z')
			sum += 10;
	}
	printf("%d\n", sum);
	return 0;
}