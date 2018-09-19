#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
char clothes[35][25];
vector<int> h[100001];
int getHash(char* str) {
	int len = strlen(str);
	int ret = 0;
	for (int i = 0;i < len;i++) {
		ret += (str[i] - '0') * 26;
		ret %= 100001;
	}
	return ret;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 0;t < T;t++) {
		int n, idx = 0;
		scanf("%d", &n);
		for (int i = 0;i < n;i++) {
			char str[21];
			scanf("%s%s", clothes[i], str);
			int hash_idx = getHash(str);
			h[hash_idx].push_back(i);
		}

		int ans = 1;
		for (int i = 0;i < 100001;i++) {
			ans *= (h[i].size() + 1);
		}
		ans--;
		printf("%d\n", ans);

		for (int i = 0;i < 100001;i++) {
			h[i].clear();
		}
	}

}