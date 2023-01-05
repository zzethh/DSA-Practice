#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

class Node {
public:
	char data;
	unordered_map<char, Node*> m;
	bool isTerminal;

	Node(char d) {
		data = d;
		isTerminal = false;
	}
};

class Trie {
public:
	Node* root;
	Trie() {
		root = new Node('\0');
	}

	void insert(string word) {
		Node* temp = root;
		for (char ch : word) {
			if (temp->m.count(ch) == 0) {
				Node* n = new Node(ch);
				temp->m[ch] = n;
			}
			temp = temp->m[ch];
		}
		temp->isTerminal = true;
	}

	bool search(string word) {
		Node* temp = root;
		for (char ch : word) {
			if (temp->m.count(ch) == 0) {
				return false;
			}
			temp = temp->m[ch];
		}
		return temp->isTerminal;
	}
};

int main()
{
	string words[] = {"apple", "ape", "news", "no"};
	Trie t;
	for (auto w : words) {
		t.insert(w);
	}
	cout << t.search("apefg");
	return 0;
}
