#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
using namespace std;

typedef struct node* nptr;
typedef struct node {
	int val;
	nptr left;
	nptr right;
	node(int v) {
		val = v, left = 0, right = 0;
	}
};

nptr root = 0;

void travel(nptr nd) {
	if (nd == 0)return;
	travel(nd->left);
	travel(nd->right);
	printf("%d\n", nd->val);
}

void insert(int v) {
	nptr nd = new node(v);
	if (root == 0) {
		root = nd;
		return;
	}
	nptr n = root;
	while (true) {
		if (v < n->val) {
			if (n->left == 0) {
				n->left = nd;
				break;
			}
			n = n->left;
		}
		else {
			if (n->right == 0) {
				n->right = nd;
				break;
			}
			n = n->right;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	int val;
	while (scanf("%d", &val) != EOF) {
		insert(val);
	}
	travel(root);
}