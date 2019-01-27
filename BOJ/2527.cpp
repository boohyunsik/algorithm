#include <stdio.h>

int main() {
	long long a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	long long r = a * b * c;
	int n[10] = { 0, };
	while (r > 0) {
		int idx = r % 10;
		n[idx]++;
		r /= 10;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", n[i]);
	}
}
