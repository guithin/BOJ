#include<bits/stdc++.h>
using namespace std;

struct que {
	struct node {
		node* bck;
		int val;
		node() {
			bck = nullptr; val = 0;
		};
		node(node* a, int b) {
			bck = a; val = b;
		}
	};
	node *head, *tail;
	size_t size;
	void push(int x) {
		node *nxt = new node(0, x);
		if (tail) {
			tail->bck = nxt;
		}
		tail = nxt;
		if (!size) {
			head = nxt;
		}
		size++;
	}
	void pop() {
		node *temp = head;
		head = head->bck;
		delete temp;
		size--;
	}
	int front() {
		return head->val;
	}
};

que temp;

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char str[10] = {};
		scanf("%s", str);
		if (str[0] == 'p'&&str[1] == 'u') {
			int tt;
			scanf("%d", &tt);
			temp.push(tt);
		}
		else if (str[0] == 'p') {
			if (temp.size) {
				printf("%d\n", temp.front());
				temp.pop();
			}
			else printf("-1\n");
		}
		else if (str[0] == 'f') {
			if (temp.size)printf("%d\n", temp.front());
			else printf("-1\n");
		}
		else if (str[0] == 'b') {
			if (temp.size)printf("%d\n", temp.tail->val);
			else printf("-1\n");
		}
		else if (str[0] == 'e')
			printf("%d\n", !temp.size);
		else printf("%d\n", temp.size);
	}
	return 0;
}