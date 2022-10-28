#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	list<int> *l;
public:
	Graph(int V) {
		v = V;
		l = new list<int> [v];
	}

	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir) {
			l[j].push_back(i);
		}
	}

	void print() {
		for (int i = 0; i < v; i++) {
			cout << i << "->";
			for (auto x : l[i]) {
				cout << x << ",";
			}
			cout << endl;
		}
	}
};


int main() {
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(2, 1);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(2, 3);
	g.addEdge(3, 5);

	g.print();


	return 0;
}