#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k, w;
int mp[35][35];

class mid_queue {
private:
	priority_queue<int>maxq;
	priority_queue<int, vector<int>, greater<int>>minq;
public:
	void push(int x) {
		maxq.push(x);
		if (maxq.size() > minq.size() + 1) {
			minq.push(maxq.top()); maxq.pop();
		}
		if (maxq.size() && minq.size() && maxq.top()>minq.top()) {
			int a = maxq.top(); maxq.pop();
			int b = minq.top(); minq.pop();
			maxq.push(b); minq.push(a);
		}
	}
	void pop() {
		maxq.pop();
		if (maxq.size() < minq.size()) {
			maxq.push(minq.top());
			minq.pop();
		}
	}
	int mid() {
		return maxq.top();
	}
};

mid_queue mq;

int main() {
	int n; scanf("%d", &n);
	while (n--) {
		int t; scanf("%d", &t);
		mq.push(t);
		printf("%d\n", mq.mid());
	}
	return 0;
}