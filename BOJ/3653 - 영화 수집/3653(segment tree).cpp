/* 세그먼트 트리 */
#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int t;
int dvd[200005];
int loc[100005] = { 0, };
int tree[600005];
int seq[100005];
int idx = 0;

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = dvd[start];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

int sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	else if (left <= start && right >= end) {
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int index, int diff) {
	if (index < start || index > end)return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &t);
	for (int testcase = 0;testcase < t; testcase++) {
		int n, m;
		scanf("%d%d", &n, &m);

		//init
		idx = 0;
		memset(tree, 0, sizeof(tree));
		memset(dvd, 0, sizeof(dvd));
		memset(loc, 0, sizeof(loc));
		memset(seq, 0, sizeof(seq));

		for (int i = 1;i <= n;i++) {
			dvd[i] = 1;
			loc[i] = n - i + 1;
		}
		init(1, 1, n + m);
		int top = n + 1;
		for (int i = 0;i < m;i++) {
			scanf("%d", &seq[idx++]);
		}
		for (int i = 0;i < idx;i++) {
			printf("%d ", sum(1, 1, n + m, loc[seq[i]], n + m) - 1);
			update(1, 1, n + m, loc[seq[i]], -1);
			update(1, 1, n + m, top, 1);
			loc[seq[i]] = top;
			top++;
		}
		printf("\n");
	}
}