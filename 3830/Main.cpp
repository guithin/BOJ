#include<stdio.h>
#include<memory.h>

struct pos {
	int n, m;
	int ver[100010];
	int val[100010];

	int find(int x) {
		if (ver[x] == x)return x;
		int temp = ver[x];
		ver[x] = find(ver[x]);
		val[x] += val[temp];
		return ver[x];
	}

	int main() {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)return 1;
		for (int i = 1; i <= n; i++)ver[i] = i;
		for (int cur = 1; cur <= m; cur++) {
			char temp[3] = { 0 };
			scanf("%s", temp);
			if (temp[0] == '?') {
				int a, b;
				scanf("%d %d", &a, &b);
				if (find(a) != find(b)) {
					printf("UNKNOWN\n");
				}
				else {
					printf("%d\n", val[a] - val[b]);
				}
			}
			else {
				int a, b, c;
				scanf("%d %d %d", &a, &b, &c);
				if (find(a) == find(b))continue;
				int t = find(a);
				ver[t] = b;
				val[t] = c - val[a];
			}
		}
		return 0;
	}
	pos() {
		memset(ver, 0, sizeof(ver));
		memset(val, 0, sizeof(val));
	}
};

int main() {
	while (1) {
		pos temp;
		if (temp.main())break;
	}
	return 0;
}