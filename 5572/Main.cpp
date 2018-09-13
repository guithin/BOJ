#include<stdio.h>
#include<algorithm>
typedef long long ll;

ll b[1011][1001] = { 0 };
ll pa[100001][2] = { 0 };

ll mini(ll a, ll b) {
	return a > b ? b : a;
}

int main()
{
	ll n, m, h, k, p = 1;
	ll x, y;
	ll s[1001] = { 0 }, a[1001] = { 0 };
	ll i, j;
	scanf("%lld %lld %lld %lld", &n, &m, &h, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &s[i]);
	}
	for (i = 1; i <= m; i++)
	{
		scanf("%lld %lld", &x, &y);
		b[y][x] = p;
		p++;
	}
	///////////////////////////
	for (i = 1; i <= n; i++)
	{
		x = i;
		for (j = 1; j < h; j++)
		{
			if (b[j][x] != 0)
			{
				pa[b[j][x]][0] = i;
				x++;
			}
			else if (b[j][x - 1] != 0)
			{
				pa[b[j][x - 1]][1] = i;
				x--;
			}
		}
		a[i] = s[x];
	}
	///////////////////////////
	//80 100 50 20
	//20 100 50 80
	long long ans = 0;
	for (i = 1; i <= k; i++)
	{
		ans += a[i];
	}
	long long min = ans;
	ll val[100010] = {};

	for (i = 1; i <= m; i++) {
		val[i] = ans;
		if (pa[i][0] <= k && pa[i][1] <= k)continue;
		else if (pa[i][0] > k&&pa[i][1] > k)continue;
		else if (pa[i][0] <= k && pa[i][1] > k) {
			val[i] += a[pa[i][1]] - a[pa[i][0]];
		}
		else if (pa[i][0] > k&&pa[i][1] <= k) {
			val[i] += a[pa[i][0]] - a[pa[i][1]];
		}
	}
	/*
	for (i = 1; i <= m; i++)
	{
		if (pa[i][0] <= k)
		{
			if (min > ans - a[pa[i][0]] + a[pa[i][1]])
			{
				min = ans - a[pa[i][0]] + a[pa[i][1]];
			}
		}
		else if (pa[i][1] <= k)
		{
			if (min > ans - a[pa[i][1]] + a[pa[i][0]])
			{
				min = ans - a[pa[i][1]] + a[pa[i][0]];
			}
		}
	}
	*/
	///////////////////////////
	printf("%lld\n", mini(ans, *std::min_element(val + 1, val + 1 + m)));
}