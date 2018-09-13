#include<stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	double ans[4] = { 0 };
	ans[0] = (double)a / c + (double)b / d;
	ans[1] = (double)c / d + (double)a / b;
	ans[2] = (double)d / b + (double)c / a;
	ans[3] = (double)b / a + (double)d / c;
	double mini = -987654321;
	int idx = 0;
	for (int i = 0; i < 4; i++) {
//		printf("%lf\n", ans[i]);
		if (ans[i] > mini) {
			mini = ans[i];
			idx = i;
		}
	}
	printf("%d\n", idx);
	return 0;
}