#include<stdio.h>
#include<algorithm>
using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int a = 1234567890, b = 1234567890;
	for (int i = 1; i <= m; i++) {
		int q, w; scanf("%d %d", &q, &w);
		a = min(a, q);
		b = min(b, w);
	}
	if (6 * b < a) a = 6 * b;
	printf("%d\n", n / 6 * a + min(a, n % 6 * b));
	return 0;
}