#include<stdio.h>

int avv(int x) {
	if (x > 0)return x;
	return -x;
}

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	int ed = x;
	int sum = 0;
	int now = 1;
	int pos = x;
	while (1) {
		pos += now;
		if (x<y&&pos>=y) {
			sum += avv(y - ed);
			break;
		}
		if (x > y&&pos <= y) {
			sum += avv(y - ed);
			break;
		}
		sum += avv(pos-ed);
//		printf("+=%d\n", avv(pos - ed));
		ed = pos;
		now *= -2;
		pos = x;
	}
	printf("%d\n", sum);
	return 0;
}