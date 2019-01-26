#include <iostream>
#include <deque>
using namespace std;
deque<int> que;
deque<int> cache1, cache2;
int main(){
	int n,x,k;
	int result1 = 0, result2 = 0, result=0;
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)que.push_back(i + 1);
	for (int i = 0; i < x; i++){
		scanf("%d", &k);
		cache1 = que;
		while (cache1.front() != k){
			result1++;
			int temp = cache1.back();
			cache1.push_front(temp);
			cache1.pop_back();
		}
		cache1.pop_front();
		cache2 = que;
		while (cache2.front() != k){
			result2++;
			int temp = cache2.front();
			cache2.push_back(temp);
			cache2.pop_front();
		}
		cache2.pop_front();
		result += result1 > result2 ? result2 : result1;
		que = result1 > result2 ? cache2 : cache1;
		result1 = 0; result2 = 0;
	}
	printf("%d", result);
	return 0;
}
