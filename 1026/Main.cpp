#include<stdio.h>
#include<algorithm>

int main() {
	int n;
	scanf("%d", &n);
	int arr[55] = { 0 };
	int brr[55] = { 0 };
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &brr[i]);
	std::sort(arr + 1, arr + n + 1);
	std::sort(brr + 1, brr + n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += arr[i] * brr[n - i + 1];
	}
	printf("%d\n", sum);
	return 0;
}