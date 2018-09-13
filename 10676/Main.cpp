#include<stdio.h>
#include<vector>
#include<memory.h>
#include<algorithm>

struct pos {
	std::vector<int>vec;
	int cost;
	bool operator<(const pos&io)const {
		return cost < io.cost;
	}
};

int s, e, n;
std::vector<pos>vec;
int dest[10010] = { 0 };
int non;

int main() {
	scanf("%d %d %d", &s, &e, &n);
	memset(dest, 40, sizeof(dest));
	non = dest[0];
	dest[s] = 0;
	for (int i = 1; i <= n; i++) {
		int ni, c;
		scanf("%d %d", &c, &ni);
		pos temp;
		temp.cost = c;
		bool flag = false;
		for (int j = 1; j <= ni; j++) {
			int qwer;
			scanf("%d", &qwer);
			if (qwer == s)flag = true;
			if (flag) {
				if (dest[qwer] > c)dest[qwer] = c;
			}
			temp.vec.push_back(qwer);
		}
		vec.push_back(temp);
	}
	std::sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		int idx = -1;
		for (int j = 0; j < vec[i].vec.size(); j++) {
			if (vec[i].vec[j] == e)idx = j;
		}
		for (int j = 0; j <= idx; j++) {
			if (dest[e] > dest[vec[i].vec[j]] + vec[i].cost)
				dest[e] = dest[vec[i].vec[j]] + vec[i].cost;
		}
/*
		for (int j = 0; j < vec[i].vec.size(); j++) {
			for (int k = j; k < vec[i].vec.size(); k++) {
				if (dest[vec[i].vec[k]] > dest[vec[i].vec[j]] + vec[i].cost)
					dest[vec[i].vec[k]] = dest[vec[i].vec[j]] + vec[i].cost;
			}
		}
*/
	}
	if (dest[e] == non)printf("-1\n");
	else printf("%d\n", dest[e]);
	return 0;
}