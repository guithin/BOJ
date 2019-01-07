#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int l; scanf("%d", &l);
		n -= (l + 1) / 2;
	}
	printf("%s\n", n > 0 ? "NO" : "YES");
	return 0;
}