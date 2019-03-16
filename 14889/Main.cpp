#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[100][100];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int pick[100] = {};
	for (int i = 0; i < n / 2; i++) {
		pick[n - i] = 1;
	}
	int ans = 987654321;
	do {
		int temp = 0;
		vector<int>vec1;
		vector<int>vec0;
		for (int i = 1; i <= n; i++) {
			if (pick[i])vec1.push_back(i);
			else vec0.push_back(i);
		}
		for (int i = 0; i < (n>>1); i++) {
			for (int j = 0; j < i; j++) {
				temp += arr[vec1[i]][vec1[j]] + arr[vec1[j]][vec1[i]];
				temp -= arr[vec0[i]][vec0[j]] + arr[vec0[j]][vec0[i]];
			}
		}
		ans = min(ans, abs(temp));
	} while (next_permutation(pick + 2, pick + 1 + n));
	printf("%d\n", ans);
	return 0;
}