#include<stdio.h>
#include<algorithm>

int n;
int chk[1000010] = { 0 };
int input[500010] = { 0 };
int temp[500010] = { 0 };
long long ans = 0;

void Sort(int l, int r) {
	if (l == r)return;
	if (l + 1 == r) {
		if (input[l] > input[r]) {
			std::swap(input[l], input[r]);
			ans++;
		}
		return;
	}
	int mid = (l + r) / 2;
	Sort(l, mid);
	Sort(mid + 1, r);
	int idxl = l;
	int idxr = mid + 1;
	for (int i = l; i <= r; i++) {
		if (idxl > mid) {
			temp[i] = input[idxr];
			idxr++;
			continue;
		}
		else if (idxr > r) {
			temp[i] = input[idxl];
			idxl++;
			continue;
		}
		else if (input[idxl] < input[idxr]) {
			temp[i] = input[idxl];
			idxl++;
			continue;
		}
		else if (input[idxl] > input[idxr]) {
			temp[i] = input[idxr];
			idxr++;
			ans += mid - idxl + 1;
			continue;
		}
	}
	for (int i = l; i <= r; i++) {
		input[i] = temp[i];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int tempp;
		scanf("%d", &tempp);
		chk[tempp] = i;
	}
	for (int i = 1; i <= n; i++) {
		int tempp;
		scanf("%d", &tempp);
		input[i] = chk[tempp];
	}
	Sort(1, n);
	printf("%lld\n", ans);
	return 0;
}