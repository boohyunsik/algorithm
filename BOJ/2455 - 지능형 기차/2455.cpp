#pragma warning (disable:4996)
#include <stdio.h>
using namespace std;

int main() {
	int p = 0;
	int ans = -1;
	for (int i = 0;i < 4;i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p -= a;
		p += b;
		if (ans < p)ans = p;
	}
	printf("%d", ans);

}