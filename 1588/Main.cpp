#include<stdio.h>
typedef long long ll;

ll cnt = 0;
ll first, left, right;
ll l = 0;
ll ans[5] = { 0 };

ll sqr(ll x, ll y) {
	long long R = 1;
	for (ll i = 1; i <= y; i++)R *= x;
	return R;
}

void f(ll L, ll R, ll n, ll deep) {
	if (L > right || R <= left )return;
	if (L >= left&&R <= right + 1) {
		int temp[5][2] = { 0 };
		temp[n][1] = 1;
		for (int i = deep; i < l; i++) {
			temp[1][0] = temp[1][1] + 2 * temp[2][1];
			temp[2][0] = temp[1][1] + temp[2][1] + 2 * temp[3][1];
			temp[3][0] = temp[1][1] + temp[3][1];
			for (int j = 1; j <= 3; j++) {
				temp[1][1] = temp[1][0];
				temp[2][1] = temp[2][0];
				temp[3][1] = temp[3][0];
			}
		}
		ans[1] += temp[1][1];
		ans[2] += temp[2][1];
		ans[3] += temp[3][1];
		return;
	}
////////////////////////////////////////////////////
/*	if (L + 1 == R) {
		if (L >= left&&R <= right + 1) {
			printf("%lld %lld %lld\n", L, R, deep);
			ans[n]++;
		}
		return;
	}*/
////////////////////////////////////////////////////
	if (n == 1) {
		f(L, (2 * L + R) / 3, 1, deep + 1);
		f((2 * L + R) / 3, (L + 2 * R) / 3, 3, deep + 1);
		f((L + 2 * R) / 3, R, 2, deep + 1);
	}
	if (n == 2) {
		f(L, (2 * L + R) / 3, 2, deep + 1);
		f((2 * L + R) / 3, (L + 2 * R) / 3, 1, deep + 1);
		f((L + 2 * R) / 3, R, 1, deep + 1);
	}
	if (n == 3) {
		f(L, (2 * L + R) / 3, 2, deep + 1);
		f((2 * L + R) / 3, (L + 2 * R) / 3, 3, deep + 1);
		f((L + 2 * R) / 3, R, 2, deep + 1);
	}
}

int main() {
	scanf("%lld %lld %lld %lld", &first, &left, &right, &l);
	f(0, sqr(3, l), first, 0);
	for (ll i = 1; i <= 3; i++)printf("%lld ", ans[i]);
	printf("\n");
	return 0;
}