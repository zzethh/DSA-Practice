#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	list<int> *l;
	list<pair<int, int> > *l2;
public:
	Graph(int V) {
		v = V;
		l = new list<int> [v];
		l2 = new list<pair<int, int> >[v];
	}

	void addEdge(int i, int j, bool undir = true) {
		l[i].push_back(j);
		if (undir) {
			l[j].push_back(i);
		}
	}

	void addEdgedir(int x, int y, int wt, bool undir = true) {

		l2[x].push_back({wt, y});
		if (undir) {
			l2[y].push_back({wt, x});
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
			cout << source << endl;
		}
	}

	void dfshelper(int source, vector<bool> &visited) {
		if (visited[source]) {
			return;
		}
		visited[source] = 1;
		cout << source << endl;
		for (auto x : l[source]) {
			dfshelper(x, visited);
		}
	}

	void dfs(int source) {
		vector<bool> visited(v, 0);
		dfshelper(source, visited);
	}

	bool containsCycledfs(int node, vector<bool> &visited, int parent) {
		visited[node] = 1;
		for (auto nbr : l[node]) {
			if (!visited[nbr]) {
				bool found = containsCycledfs(nbr, visited, node);
				if (found) return true;
			}
			else if (nbr != parent) {
				return true;
			}
		}

		return false;
	}

	bool containsCycle() {
		vector<bool> visited(v, false);
		return containsCycledfs(0, visited, -1);
	}

	bool dfs_backEdge(int node, vector<bool> &visited, vector<bool> &stack) {
		visited[node] = true;
		stack[node] = true;

		for (int nbr : l[node]) {
			if (stack[nbr]) {
				return true;
			}
			else if (visited[nbr] == false) {
				bool found = dfs_backEdge(nbr, visited, stack);
				if (found) return true;
			}
		}

		stack[node] = false;
		return false;
	}

	bool backEdge() {
		vector<bool> visited(v, 0);
		vector<bool> stack(v, 0);

		for (int i = 0; i < v; i++) {
			int source = i;
			if (!visited[source]) {
				if (dfs_backEdge(i, visited, stack)) {
					return true;
				}
			}
		}

		return false;
	}
	//tc-e*logv;
	int dijkshtra(int src, int dest) {
		vector<int> dist(v, INT_MAX);
		set<pair<int, int>> s;

		dist[src] = 0;
		s.insert({0, src});

		while (!s.empty()) {
			auto it = s.begin();
			int node = it->second;
			int disttillnow = it->first;
			s.erase(it);

			for (auto nbrPair : l2[node]) {
				int nbr = nbrPair.second;
				int currentEdge = nbrPair.first;

				if (disttillnow + currentEdge < dist[nbr]) {
					auto f = s.find({dist[nbr], nbr});

					if (f != s.end()) {
						s.erase(f);
					}

					dist[nbr] = disttillnow + currentEdge;
					s.insert({dist[nbr], nbr});
				}
			}
		}

		for (int i = 0; i < v; i++) {
			cout << "node i " << i << " dist " << dist[i] << endl;
		}

		return dist[dest];
	}

	//dijkastra for negative weight
	//for directed graph
	//if given undirected-change it to directed
	//tc-E*V;
	vector<int> bellman_ford(vector<vector<int>> edges, int src) {
		vector<int> dist(v, 1e8);
		dist[src] = 0;
		for (int i = 0; i < v - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 and dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		//nth relaxation to check neg cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 and dist[u] + wt < dist[v]) {
				return { -1};
			}
		}
		return dist;
	}

	void topodfs(int node, stack<int>&st, vector<int> &vis) {
		vis[node] = 1;
		for (auto nbr : l[node]) {
			if (!vis[nbr]) {
				topodfs(nbr, st, vis);
			}
		}
		st.push(node);
	}
	//directed acyclic graph
	void topo(vector<int>&top) {
		stack<int> st;
		vector<int> vis(v, 0);
		for (int i = 0; i < v; i++) {
			if (!vis[i]) topodfs(i, st, vis);
		}
		while (!st.empty()) {
			top.push_back(st.top());
			st.pop();
		}
	}
	//multi source shortest paths
	void floyd_marshall(vector<vector<int>> mat) {
		int n = mat.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == -1) {
					mat[i][j] = 1e9;
				}
				if (i == j) mat[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}

		//negative cycle
		for (int i = 0; i < n; i++) {
			if (mat[i][i] < 0) cout << "neg cycle presernt";
		}
	}
};


int main() {
	// Graph g(7);
	// g.addEdge(0, 1);
	// g.addEdge(1, 2);
	// g.addEdge(2, 3);
	// g.addEdge(3, 5);
	// g.addEdge(5, 6);
	// g.addEdge(4, 5);
	// g.addEdge(0, 4);
	// g.addEdge(3, 4);

	// Graph g(3);
	// g.addEdge(0, 1, false);
	// g.addEdge(1, 2, false);
	// g.addEdge(2, 0, false);

	Graph g(5);
	g.addEdgedir(0, 1, 1);
	g.addEdgedir(1, 2, 2);
	g.addEdgedir(0, 2, 4);
	g.addEdgedir(0, 3, 7);
	g.addEdgedir(3, 2, 2);
	g.addEdgedir(3, 4, 3);

	cout << g.dijkshtra(0, 3);

	return 0;
}