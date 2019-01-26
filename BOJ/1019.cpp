#pragma warning (disable:4996)
#include <stdio.h>
using namespace std;

typedef long long ll;

ll N;
ll ans[11] = { 0, };
void calc(int n, int v) {
	while (n > 0) {
		ans[n % 10]+=v;
		n /= 10;
	}
}
int main(){
	
	scanf("%lld", &N);
	ll start = 1;
	ll div = 1;
	while (start <= N) {
		while (N % 10 != 9 && start <= N) {
			calc(N, div);
			N--;
		}
		if (N < start)break;

		while (start % 10 != 0 && start <= N) {
			calc(start, div);
			start++;
		}
		start /= 10;
		N /= 10;
		
		for (int i = 0;i < 10;i++) {
			ans[i] += (N - start + 1) * div;
		}
		div *= 10;
	}

	for (int i = 0;i < 10;i++) {
		printf("%lld ", ans[i]);
	}
	
	return 0;
	
}
