#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct Node {
	char *str;
	int type; // 0 normal, 1 <int>, 2 <str>, 3 <path>
} Node;

Node *getNewNode(const char *str) {
	Node *p = (Node *)malloc(sizeof(Node));
	//p->str = strdup(str);
	p->type = 0;
	if (strcmp(str, "<int>") == 0) {
		p->type = 1;
	}
	else if (strcmp(str, "<str>") == 0) {
		p->type = 2;
	}
	else if (strcmp(str, "<path>") == 0) {
		p->type = 3;
	}
	return p;
}

vector<Node *> getList(char *str) {
	vector<Node *> ret;
	ret.push_back(getNewNode("/"));
	str++;
	char *now = str;
	while (str[0]) {
		while (str[0] && str[0] != '/') ++str;
		if (str[0] == '/') {
			str[0] = 0;
			ret.push_back(getNewNode(now));
			ret.push_back(getNewNode("/"));
			str++;
		}
		else {
			ret.push_back(getNewNode(now));
		}
		now = str;
	}
	return ret;
}

bool match_node(Node *a, Node *b) {
	switch (a->type) {
	case 0: return strcmp(a->str, b->str) == 0;
	case 1: {
		for (int i = 0; b->str[i]; i++) {
			if (b->str[i] < '0' || b->str[i] > '9') return false;
		}
		return true;
	}
	case 2:
	case 3: return true;
	}
	return 0;
}

bool match(vector<Node *> &l1, vector<Node *> &l2) {
	if (l1.size() > l2.size()) return false;
	for (int i = 0; i < l1.size(); i++) {
		if (!match_node(l1[i], l2[i])) return false;
		if (l1[i]->type == 3) return true;
	}
	return l1.size() == l2.size();
}

void output(vector<Node *> &l1, vector<Node *> &l2) {
	for (int i = 0; i < l1.size(); i++) {
		if (l1[i]->type == 0) continue;
		if (l1[i]->type == 1) {
			cout << " ";
			int j = 0;
			while (l2[i]->str[j + 1] && l2[i]->str[j] == '0') ++j;
			while (l2[i]->str[j]) cout << l2[i]->str[j++];
			continue;
		}
		cout << " " << l2[i]->str;
	}
	for (int i = l1.size(); i < l2.size(); i++) {
		cout << l2[i]->str;
	}
	cout << endl;
}

vector<vector<Node *> > rules;
vector<string> names;

int main() {
	int n, m;
	char str[1000];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		rules.push_back(getList(str));
		cin >> str;
		names.push_back(str);
	}
	while (m--) {
		cin >> str;
		vector<Node *> ret = getList(str);
		int i = 0;
		while (i < n && match(rules[i], ret) == 0) ++i;
		if (i == n) {
			cout << "404" << endl;
		}
		else {
			cout << names[i];
			output(rules[i], ret);
		}
	}
	return 0;
}