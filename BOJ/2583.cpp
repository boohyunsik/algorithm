#pragma warning (disable: 4996)
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int** arr;
int m, n, k;
int m1, n1, m2, n2;
int sm, sn, fm, fn;

int dm[4] = { -1, 0, 1, 0 };
int dn[4] = { 0, 1, 0, -1 };

int* ans;
int cnt = -1;

void dfs(int v1, int v2) {
	if (arr[v1][v2] != 0) return;
	else {
		ans[cnt]++;
		arr[v1][v2] = 3;

		for (int i = 0; i < 4; i++) {
			int nextM = v1 + dm[i];
			int nextN = v2 + dn[i];

			if (nextM < 0 || nextM >= m || nextN < 0 || nextN >= n) continue;
			else {
				if (arr[nextM][nextN] == 0) {
					dfs(nextM, nextN);
				}
			}
		}
	}
}

void sort() {
	for (int i = 0; i < cnt; i++) {
		int minIndex = i;
		for (int j = 1; j <= cnt; j++) {
			if (ans[minIndex] > ans[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			int temp = ans[i];
			ans[i] = ans[minIndex];
			ans[minIndex] = temp;
		}
	}
}

int main() {
	scanf("%d %d %d", &m, &n, &k);
	if (m <= 0 || m > 100 || n <= 0 || n > 100 || k < 0 || k > 100) return -1;

	ans = new int[m*n]();
	arr = new int*[m]();
	for (int i = 0; i < m; i++)
		arr[i] = new int[n]();

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d %d", &n1, &m1, &n2, &m2);
		arr[m - m1 - 1][n1] = 1;
		arr[m - m2][n2 - 1] = 1;

		sm = m - m2;
		sn = n1;
		fm = m - m1 - 1;
		fn = n2 - 1;

		for (int j = sm; j <= fm; j++) {
			for (int l = sn; l <= fn; l++) {
				arr[j][l] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				cnt++;
				dfs(i, j);
			}
		}
	}

	sort(ans, ans + cnt + 1);
	printf("%d\n", (cnt + 1));
	for (int i = 0; i <= cnt; i++)
		printf("%d ", ans[i]);

	for (int i = 0; i < m; i++)
		delete[] arr[i];
	delete[] arr;
	delete[] ans;

	return 0;
}
