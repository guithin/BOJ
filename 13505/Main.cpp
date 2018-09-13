#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int next[2];

	node() {
		next[0] = next[1] = 0;
	}
};

int n;
int inp[100010];
vector<node>vec;

int findMax(int x) {
	int idx = 0;
	int r = 0;
	for (int i = (1 << 30); i; i >>= 1) {
		int nbit = (x&i) ? 1 : 0;
		if (vec[idx].next[nbit ^ 1]) {
			r |= i;
			idx = vec[idx].next[nbit ^ 1];
		}
		else if (vec[idx].next[nbit]) {
			idx = vec[idx].next[nbit];
		}
		else
			break;
	}
	return r;
}

void pushX(int x) {
	int idx = 0;
	for (int i = (1 << 30); i; i >>= 1) {
		int nbit = (x&i) ? 1 : 0;
		if (!vec[idx].next[nbit]) {
			vec[idx].next[nbit] = vec.size();
			vec.push_back(node());
		}
		idx = vec[idx].next[nbit];
	}
}

int main() {
	scanf("%d", &n);
	vec.push_back(node());
	int maxi = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", inp + i);
//		if (maxi > inp[i])maxi = inp[i];
		int temp = findMax(inp[i]);
		if (temp > maxi)
			maxi = temp;
		pushX(inp[i]);
	}
	printf("%d\n", maxi);
	return 0;
}