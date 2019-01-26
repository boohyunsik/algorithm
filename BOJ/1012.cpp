#include <iostream>
#define MAX 50
using namespace std;

int map[MAX][MAX] = { 0, };
int result = 0;
int xsize, ysize, num;
void recur(int x, int y, int recurnum){
	if (x >= 0 && y >= 0 && x < xsize && y < ysize){
		if (map[x][y] == 1){
			if (recurnum == 1)result++;
			map[x][y] = 2;
			recur(x, y + 1, recurnum+1);
			recur(x + 1, y, recurnum+1);
			recur(x, y - 1, recurnum+1);
			recur(x - 1, y, recurnum+1);
		}
		else return;
	}
	else return;
}

int main(){
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &xsize, &ysize, &num);
		for (int j = 0; j < num; j++){
			int x, y;
			scanf("%d %d", &x, &y);
			map[x][y] = 1;
		}
		for (int a = 0; a < xsize; a++){
			for (int b = 0; b < ysize; b++){
				recur(a, b, 1);
			}
		}
		printf("%d\n", result);
		result = 0;
	}

}
