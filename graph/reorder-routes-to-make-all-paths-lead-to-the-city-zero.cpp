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

	void bfs(int source, set<pair<int, int>> &s, int &cnt) {
		queue<int> q;
		vector<bool> visited(v, 0);
		q.push(source);
		visited[source] = 1;
		while (!q.empty()) {
			int f = q.front();
			q.pop();
			for (auto x : l[f]) {
				if (!visited[x]) {
					if (s.find({f, x}) != s.end()) cnt++;
					q.push(x);
					visited[x] = 1;
				}
			}
		}
	}
};
class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		set<pair<int, int>> s;
		Graph g(n);
		for (auto x : connections) {
			s.insert({x[0], x[1]});
			g.addEdge(x[0], x[1]);
		}
		int cnt = 0;
		g.bfs(0, s, cnt);
		return cnt;
	}
};