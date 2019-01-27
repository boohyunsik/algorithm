#pragma warning (disable:4996)
#include <stdio.h>
using namespace std;

typedef struct Dragon {
	int x, y, d, g;
};

typedef struct Pos {
	int x, y;
};

int n;
Dragon dragon[25];
Pos sequence[1005] = { { 0, 0 }, };
int map[105][105] = { 0, };
int main(){
	
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
 		scanf("%d%d%d%d", &dragon[i].x, &dragon[i].y, &dragon[i].d, &dragon[i].g);
		sequence[0] = { dragon[i].x, dragon[i].y };
		if(dragon[i].d == 0)sequence[1] = { dragon[i].x + 1, dragon[i].y };
		else if(dragon[i].d == 1)sequence[1] = { dragon[i].x, dragon[i].y - 1};
		else if(dragon[i].d == 2)sequence[1] = { dragon[i].x - 1, dragon[i].y};
		else sequence[1] = { dragon[i].x, dragon[i].y + 1 };

		//int index = 0;
		int end = 1;
		for (int j = 0;j < dragon[i].g;j++) {
			// 끝점을 중심으로 한 회전 변환
			Pos endPoint = sequence[end];
			for (int k = end-1;k >= 0;k--) {
				int moved_x = sequence[k].x - endPoint.x;
				int moved_y = sequence[k].y - endPoint.y;

				int rotated_x = -moved_y;
				int rotated_y = moved_x;

				int final_x = rotated_x + endPoint.x;
				int final_y = rotated_y + endPoint.y;

				sequence[++end] = { final_x, final_y };
			}
		}
		for (int j = 0;j <= end;j++) {
			map[sequence[j].y][sequence[j].x] = 1;
		} 
	}

	int ans = 0;

	for (int r = 0;r < 104;r++) {
		for (int c = 0;c < 104;c++) {
			if (map[r][c] == 1 && map[r + 1][c] == 1 && map[r][c + 1] == 1 && map[r + 1][c + 1] == 1)
				ans++;
		}
	}
	printf("%d\n", ans);

}
