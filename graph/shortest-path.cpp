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

	void bfs(int source) {
		queue<int> q;
		vector<bool> visited(v, 0);
		q.push(source);
		visited[source] = 1;
		while (!q.empty()) {
			int f = q.front();
			cout << f << endl;
			q.pop();
			for (auto x : l[f]) {
				if (!visited[x]) {
					q.push(x);
					visited[x] = 1;
				}
			}
		}
	}

	void shortestDist(int source, int destination = -1) {
		queue<int> q;
		vector<bool> visited(v, 0);
		q.push(source);

		visited[source] = 1;

		vector<int> dist(v, 0);
		vector<int> parent(v, -1);

		parent[source] = source;

		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (auto x : l[f]) {
				if (!visited[x]) {
					dist[x] = dist[f] + 1;
					parent[x] = f;
					q.push(x);
					visited[x] = 1;
				}
			}
		}

		for (int i = 0; i < v; i++) {
			cout << "dist to " << i << ": " << dist[i] << endl;
		}

		if (destination != -1) {
			int temp = destination;
			while (temp != source) {
				cout << temp << "-->";
				temp = parent[temp];
			}
			cout << source;
		}
	}
};


int main() {
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 5);
	g.addEdge(5, 6);
	g.addEdge(4, 5);
	g.addEdge(0, 4);
	g.addEdge(3, 4);

	g.print();

	g.bfs(1);

	g.shortestDist(1, 6);

	return 0;
}