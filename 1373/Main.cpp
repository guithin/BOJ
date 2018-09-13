#include<stdio.h>
#include<string.h>

int ten[350000];
int two[100];
char arr[1000010] = { 0 };
int ans[1000000] = { 0 };

int sqr(int x, int y) {
	if (x == 10 && ten[y] != 0)return ten[y];
	else if (x == 2 && two[y] != 0)return two[y];
	int R = 1;
	for (int i = 1; i <= y; i++) {
		R *= x;
	}
	if (x == 10)ten[y] = R;
	else if (x == 2)two[y] = R;
	return R;
}

int main() {
	scanf("%s", arr);
	int len = strlen(arr);
	int leng = 0;
	int sum = 0;
	if (len % 3 != 0)leng = (len / 3) + 1;
	else leng = len / 3;
/*	for (int i = 0; i < len; i++) {
		if (arr[i] == '0')continue;
		int temp = sqr(10, (len - i - 1) / 3)*sqr(2, (len - i - 1) % 3);
		sum += temp;
	}*/
	for (int i = leng; i >= 1; i--) {
		int temp = 0;
		for (int j = 1; j <= 3; j++) {
			if (len - j - (i - 1) * 3 < 0)continue;
			if (arr[len - j - (i - 1) * 3] == '1')temp += sqr(2, j - 1);
		}
		ans[i] = temp;
	}
	for (int i = leng; i >= 1; i--) {
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}