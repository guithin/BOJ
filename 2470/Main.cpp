#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int abb(int x) {
	if (x > 0)
		return x;
	else
		return -x;
}

bool cmp(int a, int b) {
	if (abb(a) < abb(b))
		return true;
	else
		return false;
}

int main() {
	int n;
	int min = INT_MAX;
	int k;
	scanf("%d", &n);
	int arr[100010] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n,cmp);
	for (int i = 0; i < n - 1; i++) {
		if (abb(arr[i] + arr[i + 1]) <min) {
			min =abb( arr[i] + arr[i + 1]);
			k = i;
		}
	}
	if (arr[k] < arr[k + 1])
		printf("%d %d\n", arr[k], arr[k + 1]);
	else
		printf("%d %d\n", arr[k + 1], arr[k]);
	return 0;
}