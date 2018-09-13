#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int score[5] = { 0 };
	int sec[5] = { 0 };
	int edsec = 0;
	int state = 0;
	for (int i = 1; i <= n; i++) {
		int tempn, tempm, temps;
		scanf("%d %d:%d", &tempn, &tempm, &temps);
		score[tempn]++;
		if (score[1] > score[2] && state != 1) {
			edsec = tempm * 60 + temps;
			state = 1;
		}
		if (score[1] < score[2] && state != 2) {
			edsec = tempm * 60 + temps;
			state = 2;
		}
		if (score[1] == score[2]) {
			sec[state] += (tempm * 60 + temps) - edsec;
			state = 0;
		}
	}
	sec[state] += (48 * 60) - edsec;
	int min1 = sec[1] / 60;
	sec[1] %= 60;
	int min2 = sec[2] / 60;
	sec[2] %= 60;
	if (min1 < 10)printf("0"); printf("%d:", min1);
	if (sec[1] < 10)printf("0"); printf("%d\n", sec[1]);
	if (min2 < 10)printf("0"); printf("%d:", min2);
	if (sec[2] < 10)printf("0"); printf("%d\n", sec[2]);
	return 0;
}