#include<stdio.h>

bool check[1000010][2] = { 0 };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp >= 0)check[temp][1] = true;
		else check[-temp][0] = true;
	}
	for (int i = 1000000; i >= 0; i--) {
		if (check[i][0] == true)printf("%d\n", -i);
	}
	for (int i = 0; i <= 1000000; i++) {
		if (check[i][1] == true)printf("%d\n", i);
	}
	return 0;
}