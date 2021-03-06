// ConsoleApplication1.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <climits>
using namespace std;

typedef long long int ll;

int n;
typedef struct data {
	ll s, f;
};

data heap[100005];
int heapSize = 0;
void heapPush(data value) {
	heap[heapSize] = value;
	
	int current = heapSize;
	while (current > 0 && (heap[current].f < heap[(current - 1) / 2].f || (heap[current].f == heap[(current - 1) / 2].f && heap[current].s < heap[(current - 1) / 2].s))) {
		data temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}
	heapSize++;
}

data heapPop() {
	data ret = heap[0];
	heapSize--;

	heap[0] = heap[heapSize];
	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			//child = heap[current * 2 + 1].f < heap[current * 2 + 2].f ? current * 2 + 1 : current * 2 + 2;
			if (heap[current * 2 + 1].f < heap[current * 2 + 2].f) {
				child = current * 2 + 1;
			}
			else if (heap[current * 2 + 1].f > heap[current * 2 + 2].f) {
				child = current * 2 + 2;
			}
			else if (heap[current * 2 + 1].f == heap[current * 2 + 2].f) {
				if (heap[current * 2 + 1].s < heap[current * 2 + 2].s) {
					child = current * 2 + 1;
				}
				else {
					child = current * 2 + 2;
				}
			}
		}

		if (heap[current].f < heap[child].f)
		{
			break;
		}

		data temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	ll ans = 0;
	for (int i = 0;i < 100005;i++)heap[i].s = 0, heap[i].f = 0;
	for (int i = 0;i < n;i++) {
		data t;
		scanf("%lld%lld", &t.s, &t.f);
		heapPush(t);
	}
	ll time = 0;
	while (heapSize > 0) {
		data t = heapPop();
		if (t.s >= time) {
			time = t.f;
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;

}