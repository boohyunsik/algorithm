#pragma warning(disable:4996)
#include <stdio.h>

int n;
typedef struct croak {
	char state = 0;
};

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int t = 1;t <= n;t++) {
		croak arr[2501];

		int answer = 0;
		int nCroak = 0;

		char buf[2501] = { 0, };
		for (int i = 0; i < 2501; i++) {
			arr[i].state = 0;
		}
		scanf("%s", buf);

		int idx = 0;

		while (buf[idx] != 0) {
			char c = buf[idx];
			if (c == 'c') {
				if (nCroak == 0) {
					nCroak++;
					arr[0].state = 'c';
				}
				else {
					bool check = false;
					for (int i = 0;i < nCroak;i++) {
						if (arr[i].state == 'k') {
							check = true;
							arr[i].state = 'c';
							break;
						}
					}
					if (!check) {
						arr[nCroak].state = 'c';
						nCroak++;
					}
				}
			}
			else if (c == 'r') {
				bool check = false;
				for (int i = 0;i < nCroak;i++) {
					if (arr[i].state == 'c') {
						arr[i].state = 'r';
						check = true;
						break;
					}
				}
				if (!check) {
					nCroak = -1;
					break;
				}
			}
			else if (c == 'o') {
				bool check = false;
				for (int i = 0;i < nCroak;i++) {
					if (arr[i].state == 'r') {
						arr[i].state = 'o';
						check = true;
						break;
					}
				}
				if (!check) {
					nCroak = -1;
					break;
				}
			}
			else if (c == 'a') {
				bool check = false;
				for (int i = 0;i < nCroak;i++) {
					if (arr[i].state == 'o') {
						arr[i].state = 'a';
						check = true;
						break;
					}
				}
				if (!check) {
					nCroak = -1;
					break;
				}
			}
			else {
				bool check = false;
				for (int i = 0;i < nCroak;i++) {
					if (arr[i].state == 'a') {
						arr[i].state = 'k';
						check = true;
						break;
					}
				}
				if (!check) {
					nCroak = -1;
					break;
				}
			}
			idx++;
		}
		for (int i = 0;i < nCroak;i++) {
			if (arr[i].state != 'k') {
				nCroak = -1;
				break;
			}
		}
		printf("#%d %d\n", t, nCroak);

	}
}