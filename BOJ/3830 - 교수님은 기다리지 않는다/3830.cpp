#pragma warning (disable:4996)
#include <stdio.h>
#include <vector>
#define MAX 100005
using namespace std;
typedef long long ll;
int parent[MAX];
int Rank[MAX];
bool visit[MAX] = { 0, };
ll dist[MAX];
vector<pair<int, int>> map[MAX];
typedef struct query {
	bool sameTree;
	int a;
	int b;
};

query query_arr[MAX];
int idx = 0;

int find(int u) {
	// u가 속한 트리의 루트를 반환
	if (u == parent[u])return u;

	return find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);

	// 부모가 같다 => 같은 셋이므로 합칠 필요가 없다.
	if (u == v) return;

	if (Rank[u] > Rank[v]) {
		// swap(u, v)
		int temp = u;
		u = v;
		v = temp;
	}

	parent[u] = v;

	if (Rank[u] == Rank[v]) Rank[v]++;
}

void dfs(int c, ll w) {
	visit[c] = 1;
	dist[c] = w;
	for (int i = 0;i < map[c].size();i++) {
		int next = map[c][i].first;
		ll ww = map[c][i].second;
		if (!visit[next]) {
			dfs(next, w + ww);
		}
	}
}

int main() {
	int n, m;
	while (true) {
		scanf("%d%d", &n, &m);
		memset(map, 0, sizeof(map));
		for (int i = 0;i < MAX;i++) {
			parent[i] = i;
			Rank[i] = 0;
		}
		if (n == 0 && m == 0)return 0;
		idx = 0;
		for (int i = 0;i < m;i++) {
			char oper;
			scanf(" %c", &oper);
			if (oper == '!') {
				int a, b, d;
				scanf("%d%d%d", &a, &b, &d);
				map[b].push_back({ a, d });
				map[a].push_back({ b, -d });
				merge(a, b);
			}
			else if (oper == '?') {
				int a, b;
				scanf("%d%d", &a, &b);
				query_arr[idx++] = { find(a) == find(b), a, b };
			}
		}

		for (int i = 0;i < MAX;i++) {
			visit[i] = 0;
			dist[i] = 0;
		}
		for (int i = 0;i < n;i++) {
			if (!visit[i]) {
				dfs(i, 0);
			}
		}
		for (int i = 0;i < idx;i++) {
			if (query_arr[i].sameTree)printf("%lld\n", -dist[query_arr[i].b] + dist[query_arr[i].a]);
			else printf("UNKNOWN\n");
		}
	}
}