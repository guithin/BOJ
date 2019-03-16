#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;

ll maxS = INT_MIN, minS = INT_MAX, result, N;
ll ar[13];

void backtrack(ll cur, ll plus, ll sub, ll mul, ll div) {
	// ��� �����ڸ� �� �� ��� ����
	if (plus == 0 && sub == 0 && mul == 0 && div == 0) {
		maxS = max(maxS, result);
		minS = min(minS, result);
		return;
	}

	if (plus > 0) {
		result += ar[cur];
		backtrack(cur + 1, plus - 1, sub, mul, div);
		result -= ar[cur];
	}
	if (sub > 0) {
		result -= ar[cur];
		backtrack(cur + 1, plus, sub - 1, mul, div);
		result += ar[cur];
	}
	if (mul > 0) {
		result *= ar[cur];
		backtrack(cur + 1, plus, sub, mul - 1, div);
		result /= ar[cur];
	}
	if (div > 0) {
		ll temp = result;
		result /= ar[cur]; // ������ ���� ó��
		backtrack(cur + 1, plus, sub, mul, div - 1);
		result = temp;
	}
}


int main() {
	ll numOfPlus, numOfSub, numOfMul, numOfDiv;
	cin >> N;
	for (ll i = 0; i < N; i++)
		cin >> ar[i];
	cin >> numOfPlus >> numOfSub >> numOfMul >> numOfDiv;
	result = ar[0];
	//�ʱⰪ ar[0]�� result�� �ְ� ���� ar[1] ���̿��� ���� ������ �����ֱ� ����
	backtrack(1, numOfPlus, numOfSub, numOfMul, numOfDiv);
	cout << maxS << '\n';
	cout << minS << '\n';
}