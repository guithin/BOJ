#include<stdio.h>

int input[100010] = { 0 };
bool check[100010] = { 0 };
bool check2[100010] = { 0 };
int stack[100010] = { 0 };
int idx = 0;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			check[input[i]] = true;
			continue;
		}
		if (input[i - 1] > input[i] + 1) {
			bool flag = false;
			for (int j = input[i]+1; j < input[i - 1]; j++) {
				if (check[j] == false) {
					flag = true;
					break;
				}
			}
			if (flag == true) {
				printf("NO\n");
				return 0;
			}
		}
		check[input[i]] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j <= input[i]; j++) {
				printf("+\n");
				stack[idx] = j;
				idx++;
			}
			printf("-\n");
//			idx--;
			continue;
		}
		for (int j = stack[idx - 1]+1; j <= input[i]; j++) {
			printf("+\n");
			stack[idx] = j;
			idx++;
		}
		printf("-\n");
//		idx--;
	}
	return 0;
}