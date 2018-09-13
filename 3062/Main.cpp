#include<stdio.h>


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int a[10] = { 0 };
		int b[10] = { 0 };
		int n, np;
		scanf("%d", &n);
		int k = 1;
		int temp = n;
		int count = 0;
		while (1) {
			if (temp == 0) {
				k--;			//자릿수 완성 ^^
				break;
			}
			a[k] = temp % 10;	//a[i]에 n의 왼쪽부터 i번째 숫자가 들어감
			temp = temp / 10;
			k++;
		}
		for (int i=k; i > 0; i--) {
			b[k - i + 1] = a[i] + a[k - i+1];
		}
		if (b[k] >= 10)
			k++;
		for (int i = 1; i <= k; i++) {
			if (b[i] >= 10) {
				b[i] -= 10;
				b[i + 1] ++;
			}
		}
		for (int i = 1; i <= k; i++) {
			if (b[i] == b[k - i + 1])
				count++;
		}
		if (count == k)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}