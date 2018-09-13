#include<stdio.h>

char daystr[20][20] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int main() {
	long long Th1, Tm1, Th2, Tm2;
	long long Fh1, Fm1, Fh2, Fm2;
	scanf("%lld:%lld", &Fh1, &Fm1);
	scanf("%lld:%lld", &Fh2, &Fm2);
	scanf("%lld:%lld", &Th1, &Tm1);
	scanf("%lld:%lld", &Th2, &Tm2);
	Fm1 += Fh1 * 60;
	Fm2 += Fh2 * 60;
	Tm1 += Th1 * 60;
	Tm2 += Th2 * 60;
	long long chk = 0;
	while (1) {
		if ((Tm1*chk + Fm1 - Fm2) % Tm2 == 0 && (Tm1*chk + Fm1 - Fm2) >= 0)break;
		if (chk > Tm2) {
			printf("Never\n");
			return 0;
		}
		chk++;
	}
	long long ansm = (Tm1*chk + Fm1) % 60;
	long long ansh = (Tm1*chk + Fm1) / 60;
	long long day = ansh / 24;
	day %= 7;
	ansh %= 24;
	printf("%s\n", daystr[day]);
	printf("%.02d:%.02d\n", ansh, ansm);
	return 0;
}