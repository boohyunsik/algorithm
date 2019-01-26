#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long int pascal[40][40] = { { 1, }, { 1, 1, 0, }, };
int main(){
	for (int i = 2; i < 40; i++){
		for (int j = 0; j < i+1; j++){
			if (j == 0){
				pascal[i][0] = 1;
				continue;
			}
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i-1][j];
		}
	}
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%llu\n", pascal[m][n]);
	}
}
