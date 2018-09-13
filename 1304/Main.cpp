#include<stdio.h>
#include<vector>

std::vector<int>vec;
int table[30010] = { 0 };
int select[30010] = { 0 };
std::vector<int>arr;

int find(int x) {
	if (table[x] == x)return x;
	return table[x] = find(table[x]);
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)table[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a < b)continue;
		for (int j = b; j <= a; j++) {
			table[j] = find(b);
		}
	}
	for (int i = 1; i <= n; i++) {
		select[find(i)]++;
	}
	for (int i = 1; i <= n; i++) {
		if (select[i])vec.push_back(select[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (!(n%i))arr.push_back(i);
	}
	for (int i = 0; i < arr.size(); i++) {
		int temp = 0;
		bool flag = true;
		for (int j = 0; j < vec.size(); j++) {
			temp += vec[j];
			if (temp == arr[i])temp = 0;
			if (temp > arr[i]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			printf("%d\n", n / arr[i]);
			return 0;
		}
	}
	return 0;
}