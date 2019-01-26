#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int x, y;
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &x, &y);
		int len = y - x;
		int ans = 0;
		int center = sqrt((double)len);
		int sum_length = ((center)*(center + 1)) / 2;
		if (sum_length*2 == len){
			printf("%d\n", 2 * center);
		}
		else if (sum_length*2 > len){
			int temp = (center - 1)*(center) / 2;
			int remain = len - sum_length - temp;
			if (remain == 0)printf("%d\n", 2 * center - 1);
			else if (remain > 0)printf("%d\n", 2 * center);
		}
		else if (sum_length * 2 < len){
			printf("%d\n", 2 * center + 1);
		}
	}
}
