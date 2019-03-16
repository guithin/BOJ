#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;

ll maxS = INT_MIN, minS = INT_MAX, result, N;
ll ar[13];

void backtrack(ll cur, ll plus, ll sub, ll mul, ll div) {
	// 모든 연산자를 다 쓴 경우 종료
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
		result /= ar[cur]; // 나누기 연산 처리
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
	//초기값 ar[0]은 result에 넣고 다음 ar[1] 사이에서 부터 연산자 끼워넣기 시작
	backtrack(1, numOfPlus, numOfSub, numOfMul, numOfDiv);
	cout << maxS << '\n';
	cout << minS << '\n';
}