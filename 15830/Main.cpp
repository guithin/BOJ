#include<stdio.h>

int main() {
	double v, w, d;
	scanf("%lf %lf %lf", &v, &w, &d);
	int ans = 0;
	while (5.0 * w*w / (v*v) < d) {
		d -= 5.0 * w*w / (v*v);
		v *= 4;
		w *= 5;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}