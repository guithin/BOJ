#include<stdio.h>

int abb(int x) {
	if (x > 0)return x;
	else return -x;
}

int main() {
	char str[60] = { 0 };
	int arr[200][2] = { 0 };
	bool check[200] = { 0 };
	int status[200] = { 0 };
	int cnt = 0;
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++) {
		if (check[str[i]]==false) {
			check[str[i]] = true;
			arr[str[i]][0] = i;
		}
		else {
			arr[str[i]][1]=i;
		}
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		int open[200] = { 0 };
		for (int j = arr[i][0]+1; j < arr[i][1]; j++) {
			open[str[j]]++;
		}
		for (int j = 'A'; j <= 'Z'; j++) {
			if (open[j] == 1)cnt++;
		}
	}
	printf("%d\n", cnt/2);
	return 0;
}