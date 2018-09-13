#include<bits/stdc++.h>
using namespace std;

int n;
int inp[200][2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char a;
		int b;
		scanf(" %c %d", &a, &b);
		inp[a][b & 1]++;
	}
	int ans = 0;
	for (int b = 0; b < 2; b++) {
		for (int e = 0; e < 2; e++) {
			for (int s = 0; s < 2; s++) {
				for (int i = 0; i < 2; i++) {
					for (int g = 0; g < 2; g++) {
						for (int o = 0; o < 2; o++) {
							for (int m = 0; m < 2; m++) {
								int temp = (b + e + s + s + i + e)*(g + o + e + s)*(m + o + o);
								if (temp & 1) continue;
								ans += inp['B'][b] * inp['E'][e] * inp['S'][s] * inp['I'][i] * inp['G'][g] * inp['O'][o] * inp['M'][m];
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}