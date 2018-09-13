#include<stdio.h>
#include<memory.h>
using namespace std;

struct pos {
	int cn[10];
	int n[10];
	bool ex;
	bool ce;
	pos() {
		memset(n, 0, sizeof(n));
		memset(cn, 0, sizeof(cn));
		ex = false;
		ce = false;
	}
};

pos vec[100001];
int ux = 0;
char buf[100];

bool pu() {
	int idx = 0;
	for (int i = 0; buf[i]; i++) {
		if (vec[idx].ex)return false;
		if (!vec[idx].cn[buf[i] - '0']) {
			vec[idx].n[buf[i] - '0'] = ux++;
		}
		vec[idx].cn[buf[i] - '0']++;
		vec[idx].ce = true;
		idx = vec[idx].n[buf[i] - '0'];
	}
	if (vec[idx].ce || vec[idx].ex)return false;
	return vec[idx].ex = true;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(vec, 0, sizeof(vec));
		ux = 1;
		int n;
		scanf("%d", &n);
		bool flag = true;
		while (n--) {
			scanf("%s", buf);
			if (!pu())flag = false;
		}
		printf("%s\n", flag ? "YES" : "NO");
	}
	return 0;
}