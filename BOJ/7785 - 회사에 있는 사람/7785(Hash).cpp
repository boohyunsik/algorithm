#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX 100005
using namespace std;

typedef struct Person {
	char name[20];
	bool attendance;
	Person(const char* str) {
		for (int i = 0;i < 20;i++)name[i] = str[i];
		attendance = true;
	}
};

bool cmp(const Person &a, const Person &b) {
	return strcmp(a.name, b.name) < 0 ? false : true;
}


typedef struct Hash {
	vector<Person> h[MAX];
	int size;

	Hash() {
		size = 0;
	}
	
	void insert(const char* str) {
		int len = strlen(str);
		long long idx = 0; 
		long long div = 1;
		for (int i = 0;i < len;i++) {
			char c = str[i];

			if (c < 'a') {
				// 대문자
				idx += ((c - 'A') * div);
			}
			else if (c >= 'a') {
				// 소문자
				idx += ((c - 'a' + 26) * div);
			}
			idx %= MAX;
			div *= 52;
		}
		Person p(str);
		h[idx].push_back(p);
		size++;
	}

	void leave(const char* str) {
		int len = strlen(str);
		long long idx = 0;
		long long div = 1;
		for (int i = 0;i < len;i++) {
			char c = str[i];

			if (c < 'a') {
				// 대문자
				idx += ((c - 'A') * div);
			}
			else if (c >= 'a') {
				// 소문자
				idx += ((c - 'a' + 26) * div);
			}
			idx %= MAX;
			div *= 52;
		}
		
		for (int i = 0;i < h[idx].size();i++) {
			if (strcmp(h[idx][i].name, str) == 0) {
				h[idx][i].attendance = false;
				h[idx][i].name[0] = 0;
				break;
			}
		}
	}
};

Hash hash_table;
vector<Person> names;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		char name[20], str[20];
		scanf("%s%s", name, str);
		if (str[0] == 'e') {
			hash_table.insert(name);
		}
		else {
			hash_table.leave(name);
		}
	}

	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < hash_table.h[i].size();j++) {
			if (hash_table.h[i][j].attendance) {
				names.push_back(hash_table.h[i][j]);
			}
		}
	}
	
	sort(names.begin(), names.end(), cmp);
	for (int i = 0;i < names.size();i++) {
		printf("%s\n", names[i].name);
	} 
}