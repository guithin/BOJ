#include<iostream>
using namespace std;

int x[5], y[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 1; i <= 3; i++) {
		cin >> x[i] >> y[i];
	}
	int chk = x[1] * y[2] + x[2] * y[3] + x[3] * y[1] - (x[1] * y[3] + x[2] * y[1] + x[3] * y[2]);
	if (!chk)cout << "0\n";
	else if (chk < 0)cout << "-1\n";
	else cout << "1\n";
	return 0;
}