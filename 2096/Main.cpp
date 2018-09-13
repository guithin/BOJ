#include<iostream>
#include<algorithm>
using namespace std;

int n;
int dp_min[3][2];
int dp_max[3][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int in1, in2, in3;
		cin >> in1 >> in2 >> in3;
		dp_min[0][0] = in1 + min(dp_min[0][1], dp_min[1][1]);
		dp_max[0][0] = in1 + max(dp_max[0][1], dp_max[1][1]);

		dp_min[1][0] = in2 + min({ dp_min[0][1], dp_min[1][1], dp_min[2][1] });
		dp_max[1][0] = in2 + max({ dp_max[0][1], dp_max[1][1], dp_max[2][1] });

		dp_min[2][0] = in3 + min(dp_min[2][1], dp_min[1][1]);
		dp_max[2][0] = in3 + max(dp_max[2][1], dp_max[1][1]);

		dp_min[0][1] = dp_min[0][0];
		dp_max[0][1] = dp_max[0][0];

		dp_min[1][1] = dp_min[1][0];
		dp_max[1][1] = dp_max[1][0];

		dp_min[2][1] = dp_min[2][0];
		dp_max[2][1] = dp_max[2][0];
	}
	cout << max({ dp_max[0][1], dp_max[1][1], dp_max[2][1] }) << ' ' << min({ dp_min[0][1], dp_min[1][1], dp_min[2][1] }) << '\n';
	return 0;
}