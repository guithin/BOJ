#include<stdio.h>

int main() {
	char str[55] = { 0 };
	scanf("%s", str);
	int arr[200] = { 0 };
	for (int i = 0; str[i] != 0; i++) {
		arr[str[i]]++;
	}
	int mid = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (arr[i] & 1) {
			if (mid != 0) {
				printf("I'm Sorry Hansoo\n");
				return 0;
			}
			mid = i;
		}
	}
	arr[mid]--;
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 0; j < arr[i] / 2; j++)
			printf("%c", i);
	}
	if(mid)
		printf("%c", mid);
	for (int i = 'Z'; i >= 'A'; i--) {
		for (int j = 0; j < arr[i] / 2; j++)
			printf("%c", i);
	}
	printf("\n");
	return 0;
}