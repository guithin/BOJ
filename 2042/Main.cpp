#include<stdio.h>
#include<stdlib.h>
typedef long long ll;

void FillTree(ll* tree, ll n);
void ChangeNum(ll* tree, ll count, ll num);
long long FindSum(ll* tree, ll l, ll r, ll num, ll curIndexStart, ll curIndexFin);

int main() {
	ll n, m, k, startNum = 1, num;
	ll a, b, c;
	ll* tree;

	//input
	scanf("%lld %lld %lld", &n, &m, &k);
	while (startNum < n) { startNum <<= 1; }
	tree = (ll*)calloc(2 * startNum, sizeof(ll));
	for (ll i = 0; i<n; i++) {
		scanf("%lld", &num);
		tree[startNum + i] = num;
	}

	//���׸�Ʈ Ʈ�� ä���...
	FillTree(tree, startNum);

	for (ll i = 0; i<m + k; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) {
			//a�� 1�̸� ���׸�Ʈ Ʈ������ �ٲٰ� �����Ѵ�.
			ChangeNum(tree, startNum + b - 1, c);
		}
		else {
			//a�� 2�̸� b���� c���� ���� ���Ѵ�.
			printf("%lld\n", FindSum(tree, b, c, 1, 1, startNum));
		}
	}

	free(tree);

	return 0;
}

void FillTree(ll* tree, ll n) {
	//tree�� ä���.
	for (ll i = n - 1; i>0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

void ChangeNum(ll* tree, ll count, ll num) {
	//count��° ���ڸ� num���� �ٲٰ� Ʈ���� �����Ѵ�.
	ll temp = tree[count];
	tree[count] = num;
	while (count != 0) {
		tree[count / 2] = tree[count / 2] - temp + num;
		count /= 2;
	}
}

long long FindSum(ll* tree, ll l, ll r, ll curIndex, ll curIndexStart, ll curIndexFin) {
	//l���� r������ ���� ���Ѵ�.
	long long answer = 0;
	ll curIndexMid = (curIndexStart + curIndexFin) / 2;
	if (l <= curIndexStart && curIndexFin <= r) {
		return tree[curIndex];
	}
	if ((curIndexStart > r || curIndexFin < l)) {
		return 0;
	}
	answer = FindSum(tree, l, r, curIndex * 2, curIndexStart, curIndexMid)
		+ FindSum(tree, l, r, curIndex * 2 + 1, curIndexMid + 1, curIndexFin);

	return answer;
}