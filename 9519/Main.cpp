#include<stdio.h>
#include<string.h>

char str[31010] = { 0 };

int main() {
	int x;
	scanf("%d", &x);
	scanf("%s", str);
	int len = strlen(str);
	if (len % 2 == 0) {
		int arr[31010] = { 0 };
		int ii = 1;
		for (int i = 1; i <= len / 2; i++) {
			arr[2 * i - 1] = ii;
			ii++;
		}
		for (int i = 1; i <= len / 2; i++) {
			arr[len - 2 * (i - 1)] = ii;
			ii++;
		}
		int k = arr[2];
		int kk = 1;
		while (k != 2) {
			k = arr[k];
			kk++;
		}
		x %= kk;
		for (int i = 1; i <= x; i++) {
			char temp[31010] = { 0 };
			int idx = 0;
			for (int j = 0; j < (len + 1) / 2; j++) {
				temp[idx] = str[j * 2];
				idx++;
			}
			for (int j = 0; j < (len) / 2; j++) {
				temp[idx] = str[len - 2 * j - 1];
				idx++;
			}
			for (int j = 0; j < len; j++) {
				str[j] = temp[j];
			}
		}
		for (int i = 0; i < len; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	else {
		int arr[31010] = { 0 };
		int ii = 1;
		for (int i = 1; i <= (len+1)/2; i++) {
			arr[2*i-1] = ii;
			ii++;
		}
		for (int i = 1; i <= (len - 1) / 2; i++) {
			arr[len - 2 * (i - 1)-1] = ii;
			ii++;
		}
		int k = arr[2];
		int kk = 0;
		while(k!=2){
			kk++;
			k = arr[k];
		}
		x %= (kk + 1);
		for (int i = 1; i <= x; i++) {
			int idx = 0;
			char temp[31010] = { 0 };
			for (int j = 0; j < (len + 1) / 2; j++) {
				temp[idx] = str[2 * j];
				idx++;
			}
			for (int j = 0; j < (len-1) / 2; j++) {
				temp[idx] = str[len - 2 * j - 2];
				idx++;
			}
			for (int j = 0; j < len; j++) {
				str[j] = temp[j];
			}
		}
		for (int i = 0; i < len; i++) {
			printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}