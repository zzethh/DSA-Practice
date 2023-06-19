#include<bits/stdc++.h>
using namespace std;


// using ll = long long;

#define pb push_back
#define z(a) (int)a.size()
#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()

#define ll long long

class node {
public:
	string key;
	int value;
	node(string key, int value) {
		this->key = key;
		this->value = value;
	}
};

class lru {
public:
	int maxsize;
	list<node> l;
	unordered_map<string, list<node>::iterator> m;

	lru(int maxsize) {
		this->maxsize = maxsize > 1 > maxsize: 1;
	}

	void insert(string key, int value) {
		if (m.count(key) != 0) {
			auto it = m[key];
			it->value = value;
		}
		else {
			if (l.size() == maxsize) {
				node last = l.back();
				m.erase(last.key;)
				l.pop_back();
			}

			node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
		}
	}

	int getvalue(string key) {
		if (m.count(key) != 0) {
			auto it = m[key];

			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin()->value;
		}
		return NULL;
	}

	string recentkey() {
		return l.front().key;
	}
};

// Driver code
int main()
{



	return 0;
}

