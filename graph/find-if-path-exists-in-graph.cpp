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

	void dfs(int src, vector<bool> &visited) {
		if (visited[src]) return;
		visited[src] = 1;
		for (auto x : l[src]) {
			dfs(x, visited);
		}
	}

};

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		Graph g(n + 1);
		for (auto x : edges) {
			g.addEdge(x[0], x[1]);
		}

		vector<bool> visited(n, 0);
		g.dfs(source, visited);
		return visited[destination];
	}
};