#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

char inp[1000010];
char src[1000010];
int idx = 0;
int lena, lenb;
vector<int>ans;

int main() {
	while (1) {
		char c = getchar();
		if (c == '\n')break;
		inp[idx++] = c;
	}
	lena = idx;
	idx = 0;
	unsigned long long find = 0;
	while (1) {
		char c = getchar();
		if (c == '\n' || c == EOF)break;
		src[idx++] = c;
		find *= 33; find += c;
	}
	lenb = idx;
	unsigned long long match = 0;
	unsigned long long sub = 1;
	for (int i = 1; i < lenb; i++)sub *= 33;
	for (int i = 0; i < lenb; i++) {
		match *= 33; match += inp[i];
	}
	if (match == find)ans.push_back(1);
	for (int i = 0; i < lena - lenb; i++) {
		match -= sub * (unsigned long long)inp[i];
		match *= 33;
		match += inp[lenb + i];
		if (match == find) {
			ans.push_back(i + 2);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}