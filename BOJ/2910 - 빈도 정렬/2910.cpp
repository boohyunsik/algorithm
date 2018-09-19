#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Data {
	int first;
	int index;
	int count = 0;
};

vector<Data> h[1005];
vector<Data> res;

bool cmp(Data& a, Data& b) {
	if (a.count != b.count) {
		return a.count > b.count;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int n, c;
	scanf("%d%d", &n, &c);
	for (int i = 0;i < n;i++) {
		int k;
		scanf("%d", &k);
		int idx = k % 1005;
		bool check = 0;
		for (int j = 0;j < h[idx].size();j++) {
			if (h[idx][j].index == k) {
				h[idx][j].count++;
				check = 1;
				break;
			}
		}
		if (!check) {
			Data n;n.first = i;n.index = k, n.count = 1;
			h[idx].emplace_back(n);
		}
	}
	for (int i = 0;i < 1005;i++) {
		for (int j = 0;j < h[i].size();j++) {
			res.emplace_back(h[i][j]);
		}
	}
	sort(res.begin(), res.end(), cmp);

	for (int i = 0;i < res.size();i++) {
		for (int j = 0;j < res[i].count;j++) {
			printf("%d ", res[i].index);
		}
	}

}