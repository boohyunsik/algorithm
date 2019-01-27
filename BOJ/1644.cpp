#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;

long long n;
int answer = 0;
bool primes[4000001] = {false};
long long sum[283147];
int sidx = 1;
int idx = 2;

int main() {
    scanf("%lld", &n);
    primes[2] = false;
    primes[3] = false;
    sum[0] = 0;
    int limit = sqrt(n) + 1;
    while (idx <= limit) {
        if (primes[idx]) {
            idx++;
            continue;
        }
        for (int temp = idx * 2; temp <= n; temp += idx) {
            primes[temp] = true;
        }
        idx++;
    }

    for (int i=2; i<n + 1; i++) {
        if (!primes[i]) {
            sum[sidx + 1] = sum[sidx] + i;
            sidx++;
        }
    }
    
    int start = 0;
    int end = 0;

    while(end < sidx) {
        long long tsum = sum[end] - sum[start];
        if (tsum < n) {
            end++;
            //start = 0;
        }
        else if (tsum == n) {
            end++;
            //start = 0;
            answer++;
        }
        else {
            // tsum > n
            start++;
        }
    }

    if (!primes[n]) {
        answer++;
    }
    
    if (n < 2) {
        printf("0");
    }
    else {
        printf("%d", answer);   
    }
}
