#include<stdio.h>
#include<vector>

std::vector<char>left;
std::vector<char>right;
char str[100010] = { 0 };

int main() {
	scanf("%s", str);
	for (int i = 0; str[i] != 0; i++) {
		left.push_back(str[i]);
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		char temp[3] = { 0 };
		scanf("%s", temp);
		if (temp[0] == 'L'&&left.size()) {
			right.push_back(left[left.size() - 1]);
			left.pop_back();
		}
		else if (temp[0] == 'D'&&right.size()) {
			left.push_back(right[right.size() - 1]);
			right.pop_back();
		}
		else if (temp[0] == 'B'&&left.size()) {
			left.pop_back();
		}
		else if (temp[0] == 'P') {
			char temp2[3] = { 0 };
			scanf("%s", temp2);
			left.push_back(temp2[0]);
		}
/*		for (int i = 0; i < left.size(); i++)printf("%c", left[i]);
		printf(" ");
		for (int i = right.size() - 1; i >= 0; i--)printf("%c", right[i]);
		printf("\n");*/
	}
	for (int i = 0; i < left.size(); i++)printf("%c", left[i]);
	for (int i = right.size()-1; i >= 0; i--)printf("%c", right[i]);
	printf("\n");
	return 0;
}