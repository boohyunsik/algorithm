#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
using namespace std;

char str[2005];
char stack[2005];
int top = -1;

void push(char c) {
	stack[++top] = c;
}

char pop() {
	return stack[top--];
}

int main() {
	int tc = 1;
	while (true) {
		top = -1;
		scanf("%s", str);
		if (str[0] == '-')break;
		
		int len = strlen(str);
		for (int i = 0;i < len;i++) {
			if (str[i] == '{') {
				push('{');
			}
			else {
				if(stack[top] == '{')pop();
				else push('}');
			}
		}
		
		int ans = 0;
		int idx = 0;
		while (idx <= top) {
			if (stack[idx] == '}') {
				if (stack[idx + 1] == '}') {
					// }}
					ans++;
				}
				else {
					// }{
					ans += 2;
				}
			}
			else {
				// {{
				ans++;
			}
			idx += 2;
		}
		printf("%d. %d\n", tc, ans);
		tc++;

	}
}


//}}{{{{