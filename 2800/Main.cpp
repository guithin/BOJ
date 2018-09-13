#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

char str[221] = { 0 };
int arr[221] = { 0 };
vector<vector<char> > ans(1030, vector<char>(221, 0));
int ansidx = 0;
bool first = true;
int idx = 0;

struct pos{
	int open;
	int close;
};

bool cmp(const vector<char> &a, const vector<char> &b){
	if (strcmp(&(a[0]), &(b[0])) < 0)
		return true;
	else
		return false;
}

pos pick[210] = { 0 };
int pidx = 0;
bool chk[210] = { 0 };

void back(int cur){
	if (cur == pidx){
		if (first){
			first = false;
			return;
		}
		int tempidx = 0;
		for (int i = 0; str[i] != 0; i++){
			bool flag = false;
			for (int j = 0; j < pidx; j++){
				if (chk[j])continue;
				if (i == pick[j].open || i == pick[j].close){
					flag = true;
					break;
				}
			}
			if (flag==true){
				flag = false;
				continue;
			}
			else{
				ans[ansidx][tempidx] = str[i];
				tempidx++;
			}
		}
		ansidx++;
		return;
	}
	chk[cur] = true;
	back(cur + 1);
	chk[cur] = false;
	back(cur + 1);
}

int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			arr[idx] = i;
			idx++;
		}
		else if (str[i] == ')') {
			pos temp;
			temp.open = arr[idx - 1];
			temp.close = i;
			pick[pidx] = temp;
			pidx++;
			idx--;
		}
	}
	back(0);
	sort(ans.begin(), ans.begin() + ansidx, cmp);
	ans.resize(unique(ans.begin(), ans.begin() + ansidx) - ans.begin());
	for (int i = 0; i < ans.size(); i++){
		printf("%s\n", &(ans[i][0]));
	}
	return 0;
}