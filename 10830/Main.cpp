#include<stdio.h>
#include<memory.h>

typedef long long ll;

ll n, m;

struct matrix {
	ll arr[5][5];
	matrix() {
		memset(arr, 0, sizeof(arr));
	}
	matrix operator*(const matrix &io)const {
		matrix ret;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				for (ll k = 0; k < n; k++) {
					ret.arr[i][j] += arr[i][k] * io.arr[k][j];
				}
				ret.arr[i][j] %= 1000;
			}
		}
		return ret;
	}
};

matrix sqr(matrix &x, ll y) {
	if (y == 0) {
		matrix r; for (ll i = 0; i < n; i++)r.arr[i][i] = 1;
		return r;
	}
	else if (y == 1) {
		return x;
	}
	matrix t = sqr(x, y / 2);
	if (y & 1)return t*t*x;
	return t*t;
}

int main() {
	scanf("%lld %lld", &n, &m);
	matrix p;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			scanf("%lld", &p.arr[i][j]);
		}
	}
	matrix q = sqr(p, m);
	matrix T = p*p;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			printf("%lld ", q.arr[i][j] % 1000);
		}
		printf("\n");
	}
	return 0;
}