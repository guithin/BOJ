#include<stdio.h>
#include<memory.h>

int table[1010] = { 0 };
int table2[1010] = { 0 };

int main() {
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);
	memset(table, -1, sizeof(table));
	table[s] = 0;
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		for (int j = 0; j <= m; j++) {
			if (table[j] == i - 1) {
				if (j + temp <= m)table2[j + temp] = i;
				if (j - temp >= 0)table2[j - temp] = i;
			}
		}
		for (int j = 0; j <= m; j++) {
			table[j] = table2[j];
		}
	}
	for (int i = m; i >= 0; i--) {
		if (table[i] == n) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}