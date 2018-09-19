#pragma warning (disable:4996)
#include <stdio.h>
#include <stack>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

typedef struct Pos {
	int r, c, mode;
};

typedef struct Data {
	int r, c, dir;
};

Data seq[10000];
Pos cctv[10];
int cctv_idx = 0;
int idx = 0;
int map[10][10];
int n, m;
int ans = 987654321;

void up(int r, int c) {
	r--;
	while (r >= 0 && map[r][c] != 6) {
		if (map[r][c] == 0) {
			map[r][c]--;
		}
		r--;
	}
}
void left(int r, int c) {
	c--;
	while (c >= 0 && map[r][c] != 6) {
		if (map[r][c] == 0) {
			map[r][c]--;
		}
		c--;
	}
}
void right(int r, int c) {
	c++;
	while (c < m && map[r][c] != 6) {
		if (map[r][c] == 0) {
			map[r][c]--;
		}
		c++;
	}
}
void down(int r, int c) {
	r++;
	while (r < n && map[r][c] != 6) {
		if (map[r][c] == 0) {
			map[r][c]--;
		}
		r++;
	}
}
void init() {
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++) {
			if (map[i][j] < 0)map[i][j] = 0;
		}
	}
}

void calculate() {
	int result = 0;
	init();

	for (int i = 0;i < idx;i++) {
		if (seq[i].dir == UP)up(seq[i].r, seq[i].c);
		if (seq[i].dir == DOWN)down(seq[i].r, seq[i].c);
		if (seq[i].dir == LEFT)left(seq[i].r, seq[i].c);
		if (seq[i].dir == RIGHT)right(seq[i].r, seq[i].c);
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (map[i][j] == 0) {
				result++;
			}
		}
	}

	if (ans > result) {
		ans = result;
	}
}


void dfs(int i) {
	if (i == cctv_idx) {
		calculate();
		return;
	}
	int mode = map[cctv[i].r][cctv[i].c];
	if (mode == 1) {
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		dfs(i + 1);
		idx--;
		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		dfs(i + 1);
		idx--;
		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		dfs(i + 1);
		idx--;
		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		dfs(i + 1);
		idx--;
	}
	else if (mode == 2) {
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		dfs(i + 1);
		idx -= 2;

		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		dfs(i + 1);
		idx -= 2;
	}
	else if (mode == 3) {
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		dfs(i + 1);
		idx -= 2;

		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		dfs(i + 1);
		idx -= 2;

		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		dfs(i + 1);
		idx -= 2;

		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		dfs(i + 1);
		idx -= 2;
	}
	else if (mode == 4) {
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		dfs(i + 1);
		idx -= 3;

		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		dfs(i + 1);
		idx -= 3;

		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		dfs(i + 1);
		idx -= 3;

		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		dfs(i + 1);
		idx -= 3;
	}
	else {
		seq[idx++] = { cctv[i].r, cctv[i].c, UP };
		seq[idx++] = { cctv[i].r, cctv[i].c, RIGHT };
		seq[idx++] = { cctv[i].r, cctv[i].c, DOWN };
		seq[idx++] = { cctv[i].r, cctv[i].c, LEFT };
		dfs(i + 1);
		idx -= 4;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int startR, startC;
	for (int r = 0;r < n;r++) {
		for (int c = 0;c < m;c++) {
			scanf("%d", &map[r][c]);
			if (map[r][c] >= 1 && map[r][c] != 6) {
				cctv[cctv_idx++] = { r, c };
			}
		}
	}


	dfs(0);
	printf("%d", ans);

}
