#include <stdio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int cur;
int red[2], initRed[2];
int blue[2], initBlue[2];
int hole[2];
char map[11][11] = { 0, };

int ans, min = 987654321;

bool checkRed(int d) {
	if (map[red[0] + dr[d]][red[1] + dc[d]] == '#') {
		return false;
	}

	if (red[0] == hole[0] && red[1] == hole[1])
		return false;

	if (red[0] + dr[d] == blue[0] && red[1] + dc[d] == blue[1]
		&& (blue[0] != hole[0] || blue[1] != hole[1])) {
		return false;
	}
	return true;
}

bool checkBlue(int d) {
	if (map[blue[0] + dr[d]][blue[1] + dc[d]] == '#') {
		return false;
	}

	if (blue[0] == hole[0] && blue[1] == hole[1])
		return false;

	if (blue[0] + dr[d] == red[0] && blue[1] + dc[d] == red[1]
		&& (red[0] != hole[0] || red[1] != hole[1])) {
		return false;
	}

	return true;
}

void moveRed(int d) {
	red[0] += dr[d];
	red[1] += dc[d];
}

void moveBlue(int d) {
	blue[0] += dr[d];
	blue[1] += dc[d];
}

void dfs(int k, int d) {

	if (k > 10)return;

	// check whether answer
	bool cRed= false;
	bool cBlue = false;
	int prevRed_r = red[0];
	int prevRed_c = red[1];
	int prevBlue_r = blue[0];
	int prevBlue_c = blue[1];
	while (checkRed(d) || checkBlue(d)) {
		if (checkRed(d) && !cRed)
			moveRed(d);
		
		if (checkBlue(d) && !cBlue)
			moveBlue(d);

 		if (red[0] == hole[0] && red[1] == hole[1]) {
			cRed = true;
		}

		if (blue[0] == hole[0] && blue[1] == hole[1]) {
			cBlue = true;
		}

		if (cRed && cBlue)break;
	}

	if (cBlue) {
		red[0] = prevRed_r;
		red[1] = prevRed_c;
		blue[0] = prevBlue_r;
		blue[1] = prevBlue_c;
		return;
	}

	if (cRed) {
		if (min > k) {
			min = k;
		}
		red[0] = prevRed_r;
		red[1] = prevRed_c;
		blue[0] = prevBlue_r;
		blue[1] = prevBlue_c;
		return;
	}

	for (int i = 0;i < 4;i++) {
		if ((checkRed(i) || checkBlue(i)) && i != d) {
			if ((d == UP && i != DOWN) ||
				(d == DOWN && i != UP) ||
				(d == LEFT && i != RIGHT) ||
				(d == RIGHT && i != LEFT))
					dfs(k + 1, i);
		}
	}

	red[0] = prevRed_r;
	red[1] = prevRed_c;
	blue[0] = prevBlue_r;
	blue[1] = prevBlue_c;
}

int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'R') {
				initRed[0] = i;
				initRed[1] = j;
			}
			if (map[i][j] == 'B') {
				initBlue[0] = i;
				initBlue[1] = j;
			}
			if (map[i][j] == 'O') {
				hole[0] = i;
				hole[1] = j;
			}
		}
	}

	for (int i = 0;i < 4;i++) {
		red[0] = initRed[0]; red[1] = initRed[1];
		blue[0] = initBlue[0]; blue[1] = initBlue[1];
		if (checkRed(i) || checkBlue(i)) {
			dfs(1, i);
		}
	}

	if (min == 987654321) {
		printf("-1\n");
	}
	else {
		printf("%d\n", min);
	}
}
