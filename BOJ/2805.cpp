#include <stdio.h>
#include <algorithm>
#define M 1000001
using namespace std;
int n, m, tree[M], ans = 0, maximum = 0;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		scanf("%d", &tree[i]);
		if (maximum < tree[i])maximum = tree[i];
	}
	int left = 0, right = maximum, mid = (left+right)/2;
	while (left <= right){
		unsigned long long int sum = 0;
		for (int i = 0; i < n; i++){
			if (tree[i] - mid > 0)sum += (tree[i] - mid);
		}
		if (sum >= m){
			if (ans < mid)ans = mid;
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	printf("%d\n", ans);
}
