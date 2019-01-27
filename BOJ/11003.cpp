#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;

int n, l;
#define pi pair<int, int>
priority_queue<pi, vector<pi>, greater<pi> > pq;
int main() {
    scanf("%d%d", &n, &l);

    for (int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        pq.push(make_pair(t, i));

        pi top = pq.top();
        // pi.first = value
        // pi.seconde = index

        if (top.second >= i-l+1 && top.second <= i) {
            printf("%d ", top.first);
        }
        else {
            while(true) {
                pq.pop();
                pi top = pq.top();
                if (top.second >= i-l+1 && top.second <= i) {
                    printf("%d ", top.first);
                    break;
                }
            }
        }
    }
}
