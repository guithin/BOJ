#include<stdio.h>
int arr[200] = { 0 };
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char str[35] = { 0 };
		scanf("%s", str);
		arr[str[0]]++;
	}
	bool flag = true;
	for (int i = 'a'; i <= 'z'; i++) {
		if (arr[i] >= 5) {
			printf("%c", i);
			flag = false;
		}
	}
	if (flag)printf("PREDAJA");
	printf("\n");
	return 0;
}