#include <stdio.h>

int main(){

	int T;
	scanf("%d", &T);

	int startX;
	int startY;
	int destX;
	int destY;
	int num;

	for (int i = 0; i < T; i++){
		int result = 0;
		scanf("%d %d %d %d", &startX, &startY, &destX, &destY);
		scanf("%d", &num);
		for (int j = 0; j < num; j++){
			int x, y, r;
			scanf("%d %d %d", &x, &y, &r);
			
				int distfromStart = (startX - x)*(startX - x) + (startY - y)*(startY - y);
				int distfromDest = (destX - x)*(destX - x) + (destY - y)*(destY - y);

				if (distfromStart < r * r && distfromDest < r * r){
					continue;
				}
				else{
					if (distfromStart < r * r){
						result++;
					}
					if (distfromDest < r * r){
						result++;
					}
				
			}
		}
		
		printf("%d\n", result);
	}

	return 0;
}
