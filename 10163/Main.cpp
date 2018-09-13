#include<stdio.h>
#include<algorithm>
using namespace std;

int n;

int inp[110];
int map[110][110];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < d; k++) {
				inp[i]++;
				inp[map[j + a][k + b]]--;
				map[j + a][k + b] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++)printf("%d\n", inp[i]);
	return 0;
}