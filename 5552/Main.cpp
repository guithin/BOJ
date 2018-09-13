#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

struct pos {
	ll x, y;
	pos() {};
	pos(ll a, ll b) {
		x = a; y = b;
	}
};

pos inp[100010];
ll srtx[100010];
ll srty[100010];

ll absx(ll x) {
	return x > 0 ? x : -x;
}

int main() {
	ll w, h, n;
	scanf("%lld %lld %lld", &w, &h, &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld %lld", srtx + i, srty + i);
		inp[i] = pos(srtx[i], srty[i]);
	}
	sort(srtx + 1, srtx + 1 + n);
	sort(srty + 1, srty + 1 + n);

	ll midx = srtx[(n + 1) / 2];
	ll midy = srty[(n + 1) / 2];
	ll maxi = 0;
	ll sum = 0;
	for (ll i = 1; i <= n; i++) {
		sum += absx(inp[i].x - midx) + absx(inp[i].y - midy);
		if (maxi < absx(inp[i].x - midx) + absx(inp[i].y - midy))
			maxi = absx(inp[i].x - midx) + absx(inp[i].y - midy);
	}
	sum *= 2;
	sum -= maxi;

	if (!(n & 1)) {
		ll sumtemp, maxitemp, mid_x, mid_y;
		//
		sumtemp = 0;
		maxitemp = 0;
		mid_x = srtx[n / 2];
		mid_y = srty[n / 2 + 1];
		for (ll i = 1; i <= n; i++) {
			sumtemp += absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y);
			if (maxitemp < absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y))
				maxitemp = absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y);
		}
		sumtemp *= 2;
		sumtemp -= maxitemp;
		if (sumtemp < sum) {
			sum = sumtemp;
			midx = mid_x;
			midy = mid_y;
		}
		//
		sumtemp = 0;
		maxitemp = 0;
		mid_x = srtx[n / 2 + 1];
		mid_y = srty[n / 2];
		for (ll i = 1; i <= n; i++) {
			sumtemp += absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y);
			if (maxitemp < absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y))
				maxitemp = absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y);
		}
		sumtemp *= 2;
		sumtemp -= maxitemp;
		if (sumtemp < sum) {
			sum = sumtemp;
			midx = mid_x;
			midy = mid_y;
		}
		//
		sumtemp = 0;
		maxitemp = 0;
		mid_x = srtx[n / 2 + 1];
		mid_y = srty[n / 2 + 1];
		for (ll i = 1; i <= n; i++) {
			sumtemp += absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y);
			if (maxitemp < absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y))
				maxitemp = absx(inp[i].x - mid_x) + absx(inp[i].y - mid_y);
		}
		sumtemp *= 2;
		sumtemp -= maxitemp;
		if (sumtemp < sum) {
			sum = sumtemp;
			midx = mid_x;
			midy = mid_y;
		}
	}
	printf("%lld\n", sum);
	printf("%lld %lld\n", midx, midy);
	return 0;
}