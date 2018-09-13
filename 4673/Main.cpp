#include<stdio.h>

bool asdf[100010] = { 0 };

int main() {
	for (int i = 1; i <= 10000; i++) {
		int temp = i;
		int sum = i;
		while (temp != 0) {
			sum += temp % 10;
			temp /= 10;
		}
		asdf[sum] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		if (!asdf[i])printf("%d\n", i);
	}
	return 0;
}