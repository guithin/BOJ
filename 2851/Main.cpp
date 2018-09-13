#include<stdio.h>

int abb(int x) {
	if (x > 0)return x;
	else return -x;
}

int main() {
	int arr[15] = { 0 };
	int sum = 0;
	for (int i = 1; i <= 10; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= 10; i++) {
		if (abb(sum - 100) >= abb(sum + arr[i] - 100)) {
			sum += arr[i];
		}
		else break;
	}
	printf("%d\n", sum);
	return 0;
}