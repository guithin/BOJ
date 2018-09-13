#include<stdio.h>
#include<algorithm>

struct input {
	int s;
	int go;
	bool operator <(const input&io)const {
		return s < io.s;
	}
};

input so[110];

int main() {
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		input in;
		scanf("%d %d", &in.s, &in.go);
		so[i] = in;
	}
	std::sort(so + 1, so + n + 1);
	for (int i = 1; i <= n; i++) {
		if (sum < so[i].s) {
			sum = so[i].s;
		}
		sum += so[i].go;
	}
	printf("%d\n", sum);
	return 0;
}