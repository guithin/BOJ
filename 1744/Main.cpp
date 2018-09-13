#include<bits/stdc++.h>
using namespace std;

int n, ans, z;
priority_queue<int>q1;
priority_queue<int>q2;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		if (temp < 0) {
			q2.push(-temp);
		}
		else if (temp > 1) {
			q1.push(temp);
		}
		else if (!temp)z++;
		else ans++;
	}
	while (q1.size() > 1) {
		int temp = q1.top(); q1.pop();
		ans += temp * q1.top(); q1.pop();
	}
	if (q1.size()) ans += q1.top(); 
	while (q2.size() > 1) {
		int temp = q2.top(); q2.pop();
		ans += temp * q2.top(); q2.pop();
	}
	if (q2.size()) {
		if (!z) {
			ans += -q2.top();
		}
	}
	printf("%d\n", ans);
	return 0;
}