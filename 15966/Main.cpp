#include<stdio.h>

int n;
int inp[100010];
int arr[1000010];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
	}
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		arr[inp[i]] = arr[inp[i] - 1] + 1;
		if (arr[inp[i]] > maxi)maxi = arr[inp[i]];
	}
	printf("%d\n", maxi);
	return 0;
}