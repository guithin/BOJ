#include<stdio.h>
typedef long long ll;

struct pos {
	ll x, y;
};

ll n;
ll map[100][100];

pos div(ll temp, char* p, ll idx) {
	pos t;
	t.x = t.y = 0;
	if (!p[idx])return t;
	t = div(temp / 2, p, idx + 1);
	if (p[idx] == '1') {
		t.x += temp / 2;
		return t;
	}
	else if (p[idx] == '2') {
		return t;
	}
	else if (p[idx] == '3') {
		t.y += temp / 2;
		return t;
	}
	else {
		t.x += temp / 2;
		t.y += temp / 2;
		return t;
	}
}

int main() {
	scanf("%lld", &n);
	char str[100] = {};
	scanf("%s", str);
	pos temp = div((1ll << n), str, 0);

	ll x, y;
	scanf("%lld %lld", &x, &y);
	temp.x += x;
	temp.y -= y;

	ll tmp = (1ll << n);
	if (temp.x < 0 || temp.x >= tmp || temp.y < 0 || temp.y >= tmp) {
		printf("-1\n");
		return 0;
	}
	tmp >>= 1;
	for (ll i = 1; i <= n; i++, tmp >>= 1) {
		if (temp.x / tmp && temp.y / tmp) {
			temp.x %= tmp;
			temp.y %= tmp;
			str[i] = '4';
		}
		else if (temp.x / tmp) {
			temp.x %= tmp;
			str[i] = '1';
		}
		else if (temp.y / tmp) {
			temp.y %= tmp;
			str[i] = '3';
		}
		else
			str[i] = '2';
	}
	printf("%s\n", str + 1);
	return 0;
}