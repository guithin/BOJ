#include<bits/stdc++.h>
using namespace std;

struct pos {
	int val, num;
	pos() {};
	pos(int a, int b) {
		val = a; num = b;
	}
	bool operator<(const pos &io)const {
		return num > io.num;
	}
};

priority_queue<pos>q;
map<int, int>m;

int chk[10][5] = {
	{},
{2, 4},
{1, 3, 5},
{2, 6},
{1, 5, 7},
{2, 4, 6, 8},
{3, 5, 9},
{4, 8},
{5, 7, 9},
{6, 8}
};
/*
1, 2, 3
4, 5, 6
7, 8, 9
*/

int sqr[10] = { 0, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };

int find_z(int a) {
	//000,000,000
	int i = 9;
	while (a) {
		if (a % 10) {
			i--;
			a /= 10;
		}
		else
			return i;
	}
	return i;
}

int sp(int a, int f, int t) {
	int temp = a;
	temp /= sqr[f];
	temp %= 10;
	a -= temp * sqr[f];
	a += temp * sqr[t];
	return a;
}

int main() {
	pos temp(0, 0);
	for (int i = 1; i <= 9; i++) {
		int a; scanf("%d", &a);
		temp.val *= 10; temp.val += a;
	}
	q.push(pos(temp.val, 0));
	m[temp.val] = 0;
	while (q.size()) {
		pos now = q.top(); q.pop();
        if(now.val==123456780){
            printf("%d\n", now.num);
            return 0;
        }
		int idx = find_z(now.val);
		for (int i = 0; chk[idx][i]; i++) {
			int temp = sp(now.val, chk[idx][i], idx);
			if (m.find(temp) == m.end() || m[temp] > now.val + 1) {
				m[temp] = now.num + 1;
				q.push(pos(temp, m[temp]));
			}
		}
	}
	if (m.find(123456780) == m.end())
		printf("-1\n");
	else
		printf("%d\n", m[123456780]);
	return 0;
}