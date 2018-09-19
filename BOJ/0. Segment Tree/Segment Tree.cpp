#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int tree[1000];

int init(int node, int start, int end) {
	if (start == end) {
		return tree[node];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

int sum(int node, int left, int right, int start, int end) {
	if (left > end || right < start) {
		// right start end 또는 start end left
		return 0;
	}
	if (left <= start && end <= right) {
		// left start end 또는 start end right
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int index, int diff) {
	if (index < start || index > end) {
		// index start end 또는 start end index
		return;
	}
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main() {

}