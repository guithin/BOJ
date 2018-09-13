#include<stdio.h>

int arr[1100][1100] = { 0 };
int A[1100] = { 0 };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
		A[1] += arr[i][1];
	if (n == 2) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum += arr[i][j];
			}
		}
		A[1] = sum / 4;
	}
	else if (n % 2==0) {
		for (int i = 1; i < n; i += 2) {
			A[1] -= arr[i][i + 1];
		}
		A[1] /= (n - 2);
		
	}
	else if (n == 3) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				sum += arr[i][j];
			}
		}
		sum /= 4;
		A[1] = sum - arr[2][3];
	}
	else {
		for (int i = 1; i < n; i += 2) {
			A[1] -= arr[i][i + 1];
		}
		A[1] -= arr[1][n];
		A[1] /= (n - 3);
	}
	printf("%d ", A[1]);
	for (int i = 2; i <= n; i++) {
		A[i] = arr[i][1] - A[1];
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}