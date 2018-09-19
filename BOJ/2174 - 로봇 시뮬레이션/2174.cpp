#pragma warning (disable:4996)
#include<stdio.h>
#include<algorithm>
#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;
typedef struct Robot {
	int r, c, dir;
};
Robot robots[105];
int map[105][105] = { 0, };
int a, b, n, m;
bool check = true;
bool wall = false;
bool crash = false;

int p, q;

int dr[4] = {0,0,0,0};
int dc[4] = { 0,0,0,0 };
void printCrashWall(int x) {
	printf("Robot %d crashes into the wall", x);
}

void printCrashRobot(int x, int y) {
	printf("Robot %d crashes into robot %d", x, y);
}

int main() {
	scanf("%d%d%d%d", &a, &b, &n ,&m);
	for (int i = 1;i <= n;i++) {
		char c;
		int x, y;
		scanf("%d%d %c", &x, &y, &c);
		robots[i].r = b - y;
		robots[i].c = x - 1;
		map[robots[i].r][robots[i].c] = i;
		if (c == 'N')robots[i].dir = N;
		if (c == 'E')robots[i].dir = E;
		if (c == 'W')robots[i].dir = W;
		if (c == 'S')robots[i].dir = S;
	}

	for (int i = 0;i < m;i++) {
		int idx, iter;
		char order;
		scanf("%d %c%d", &idx, &order, &iter);

		if (check) {
			for (int j = 0;j < iter;j++) {
				if (order == 'R') {
					robots[idx].dir++;
					robots[idx].dir %= 4;
				}
				if (order == 'L') {
					robots[idx].dir--;
					if (robots[idx].dir == -1)robots[idx].dir = W;
					robots[idx].dir %= 4;
				}
				if (order == 'F') {
					int nextR = robots[idx].r;
					int nextC = robots[idx].c;
					if (robots[idx].dir == N) {
						nextR--;
					}
					if (robots[idx].dir == W) {
						nextC--;
					}
					if (robots[idx].dir == E) {
						nextC++;
					}
					if (robots[idx].dir == S) {
						nextR++;
					}


					if (nextR < 0 || nextR > b - 1 || nextC < 0 || nextC > a - 1) {
						p = idx;
						check = false;
						wall = true;
						break;
					}
					if (map[nextR][nextC] == 0) {
						map[robots[idx].r][robots[idx].c] = 0;
						robots[idx].r = nextR;
						robots[idx].c = nextC;
						map[nextR][nextC] = idx;
					}
					else {
						p = idx;
						q = map[nextR][nextC];
						check = false;
						crash = true;
						break;
					}
				}
			}
		}
	}
	if (wall) {
		printCrashWall(p);
	}
	if (crash) {
		printCrashRobot(p, q);
	}
	if (check) {
		printf("OK");
	}
}