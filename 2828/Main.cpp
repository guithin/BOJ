#include<stdio.h>

int main() {
	int N, M, n;
	scanf("%d %d %d", &N, &M, &n);
	int ed = 1;
	int cnt = 0;
	while(n--) {
		int temp;
		scanf("%d", &temp);
		if (ed + M - 1 < temp) {
			cnt += temp - ed - M + 1;
			ed = temp - M + 1;
		}
		else if (ed > temp) {
			cnt += ed - temp;
			ed = temp;
		}
	}
	printf("%d\n", cnt);
	return 0;
}