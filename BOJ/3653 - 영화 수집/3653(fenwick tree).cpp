#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int dvd[100005];
int tree[200005];
int n, m, t;

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(int i, int num) {
	while (i <= n + m) {
		tree[i] += num;
		i += (i & -i);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dvd, 0, sizeof(dvd));
		memset(tree, 0, sizeof(tree));
		scanf("%d%d", &n, &m);
		for (int i = 1;i <= n;i++) {
			update(i, 1);
			dvd[i] = n - i + 1;
		}
		int t = n + 1;
		for (int i = 0;i < m;i++) {
			int a;
			scanf("%d", &a);
			printf("%d ", sum(n+m) - sum(dvd[a]));
			update(dvd[a], -1);
			dvd[a] = t;
			update(t++, 1);
		}
		printf("\n");
	}
}
