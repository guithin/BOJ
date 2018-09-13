#include<stdio.h>
#include<algorithm>
#include<vector>
typedef long long ll;

struct pos {
	bool chk;
	ll num;
	pos() {};
	pos(bool b, ll a) {
		chk = b;
		num = a;
	}
	bool operator<(const pos&io)const {
		return num < io.num;
	}
};

struct qq {
	ll s, e;
	qq() {};
	qq(ll a, ll b) {
		s = a;
		e = b;
	}
};

ll n, a, b;
pos inp[500100];
std::vector<qq>ans;

int main() {
	scanf("%lld %lld %lld", &n, &a, &b);
	for (ll i = 1; i <= n; i++) {
		char temp[5] = { 0 };
		scanf("%s %lld", temp, &inp[i].num);
		if (temp[0] == 'S')inp[i].chk = true;
		else inp[i].chk = false;
	}
	std::sort(inp + 1, inp + 1 + n);
	bool ed;
	ll edd = 0;
	if (inp[1].chk) {
		ans.push_back(qq(std::min(a, inp[1].num), 0ll));
		ed = true;
		edd = inp[1].num;
	}
	else {
		ed = false;
		edd = inp[1].num;
	}
	for (ll i = 1; i <= n; i++) {
		if (ed != inp[i].chk) {
			if (ed) {
				ans[ans.size() - 1].e = (inp[i].num + edd) / 2;
				edd = inp[i].num;
				ed = inp[i].chk;
			}
			else {
				ans.push_back(qq((inp[i].num + edd - 1) / 2 + 1, 0ll));
				edd = inp[i].num;
				ed = inp[i].chk;
			}
		}
		else
			edd = inp[i].num;
	}
	if (ans[ans.size() - 1].e == 0)ans[ans.size() - 1].e = b;

	ll sum = 0;
	for (ll i = 0; i < ans.size(); i++) {
		if (ans[i].e < a)continue;
		if (ans[i].s > b)continue;
		if (ans[i].s >= a&&ans[i].e <= b)sum += ans[i].e - ans[i].s + 1;
		if (ans[i].s < a&&ans[i].e <= b)sum += ans[i].e - a + 1;
		if (ans[i].s >= a&&ans[i].e > b)sum += b - ans[i].s + 1;
		if (ans[i].s < a&&ans[i].e > b)sum += b - a + 1;
	}
	printf("%lld\n", sum);
	return 0;
}