#include<stdio.h>
#include<string.h>

char stra[20] = { 0 };
char strb[20] = { 0 };

int main() {
	scanf("%s %s", stra + 1, strb + 1);
/*	int a, b;
	scanf("%d %d", &a, &b);*/
	int maxsum = 0;
	int minsum = 0;
	for (int i = 1; stra[i] != 0; i++) {
		maxsum *= 10;
		minsum *= 10;
		if (stra[i] == '5' || stra[i] == '6') {
			maxsum += 6;
			minsum += 5;
		}
		else {
			maxsum += stra[i] - '0';
			minsum += stra[i] - '0';
		}
	}
	int temp1 = 0;
	int temp2 = 0;

	for (int i = 1; strb[i] != 0; i++) {
		temp1 *= 10;
		temp2 *= 10;
		if (strb[i] == '5' || strb[i] == '6') {
			temp1 += 6;
			temp2 += 5;
		}
		else {
			temp1 += strb[i] - '0';
			temp2 += strb[i] - '0';
		}
	}
	printf("%d %d\n", minsum + temp2, maxsum + temp1);
	return 0;
}