
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef struct Pos {
	int index, x, y;
};

Pos arr[200001];

bool cmp(Pos a, Pos b) {
	if (a.x < b.x) {
		return true;
	}
	else if (a.x == b.x) {
		if (a.y < b.y) {
			return true;
		}
	}

	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	for (int testcase = 1; testcase <= t; testcase++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &arr[i].x, &arr[i].y);
			arr[i].index = i + 1;
		}
		sort(arr, arr + n, cmp);
		int nx = arr[0].x;
		int ny = arr[0].y;
		printf("#%d %d ", testcase, arr[0].index);
		for (int i = 1; i < n; i++) {
			int cx = arr[i].x;
			int cy = arr[i].y;
			if (nx < cx && ny > cy) {
				printf("%d ", arr[i].index);
				nx = cx;
				ny = cy;
			}
		}
		printf("\n");
	}

	return 0;
}
