#pragma warning(disable:4996)
#include <stdio.h>
typedef unsigned long long lld;
lld n;

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%lld", &n);

		int left = 1, right = 1000000;
		bool answer = false;
		while (left <= right) {
			lld mid = (left + right) / 2;
			lld v = mid * mid * mid;
			if (v > n) {
				right = mid - 1;
			}
			else if (v < n) {
				left = mid + 1;
			}
			else {
				printf("#%d %d\n", tc, mid);
				answer = true;
				break;
			}
		}
		if(!answer) printf("#%d -1\n", tc);
	}
}