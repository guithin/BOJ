#include<stdio.h>
#include<algorithm>


int na[500010] = { 0 };
int ma[500010] = { 0 };

bool search(int x,int l, int r) {
	int m = (l + r) / 2;
	if (l > r)
		return false;
	if (na[m] > x) {
//		printf("%d %d %d\n", x, l, m - 1);
		return search(x, l, m - 1);
	}
	else if (na[m] < x) {
//		printf("%d %d %d\n", x, m+1, r);
		return search(x, m + 1, r);
	}
	else
		return true;
}

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &na[i]);
	}
	std::sort(na + 1, na + n+1);
/*	for (int i = 1; i <= n; i++) {
		printf("%d ", na[i]);
	}
	printf("\n");*/
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &ma[i]);
	}
	for (int i = 1; i <= m; i++) {
		if (search(ma[i], 1, n) == true)
			printf("1 ");
		else
			printf("0 ");
	}
	printf("\n");
	return 0;
}