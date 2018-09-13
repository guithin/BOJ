#include<stdio.h>
#include<vector>
struct start {
	struct pos {
		int val;
		std::vector<int>vec;
		pos() {};
		pos(int a, int b) {
			val = a;
		}
	};
	int n, m;
	pos inp[510];

	int search(int x) {
		for (int i = 1; i <= n; i++)if (inp[i].val == x)return i;
	}

	int main() {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &inp[i].val);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			int sa = search(a);
			int sb = search(b);
			if (sa < sb) inp[sa].vec.push_back(b);
			else inp[sb].vec.push_back(a);
		}
		for (int i = n - 1; i >= 0; i--) {
			int chk[510] = { 0 };
			bool flag = false;
			for (int j = 0; j < inp[i].vec.size(); j++) {
				flag = true;
				chk[search(inp[i].vec[j])] = 1;
			}
			if (flag)chk[i] = 1;
			int mini = 100000;
			int maxi = -1;
			if (!flag)continue;
			for (int j = 1; j <= n; j++) {
				if (chk[j]) {
					mini = j;
					break;
				}
			}
			for (int j = n; j >= 1; j--) {
				if (chk[j]) {
					maxi = j;
					break;
				}
			}
			int sumtemp = 0;
			for (int j = mini; j <= maxi; j++)sumtemp += chk[j];
			if (sumtemp != maxi - mini + 1) {
				printf("IMPOSSIBLE\n");
				return 0;
			}
			pos qwer = inp[mini];
			for (int j = mini; j < maxi; j++) {
				inp[j] = inp[j + 1];
			}
			inp[maxi] = qwer;
		}
		for (int i = 1; i <= n; i++) {
			printf("%d ", inp[i].val);
		}
		printf("\n");
		return 0;
	}
	start() {

	}
};

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		start temp;
		temp.main();
	}
	return 0;
}