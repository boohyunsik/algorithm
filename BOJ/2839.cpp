#include <stdio.h>
using namespace std;

int ans[5001] = { 0, };

int main() {
	ans[1] = -1;
	ans[2] = -1;
	ans[3] = 1;
	ans[4] = -1;
	ans[5] = 1;

	for (int i = 6;i <= 5000;i++) {
		if (ans[i - 3] == -1 && ans[i - 5] == -1) {
			ans[i] = -1;
		}
		else if (ans[i-3] != -1 && ans[i-5] == -1) {
			ans[i] = ans[i - 3] + 1;
		}
		else if (ans[i - 3] == -1 && ans[i - 5] != -1) {
			ans[i] = ans[i - 5] + 1;
		}
		else {
			ans[i] = ans[i - 3] < ans[i - 5] ? ans[i - 3] + 1 : ans[i - 5] + 1;
		}
	}

	int N;
	scanf("%d", &N);
	printf("%d", ans[N]);
}
