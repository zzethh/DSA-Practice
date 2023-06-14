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

	vector<bool> backEdge() {
		vector<bool> visited(v, 0);
		vector<bool> stack(v, 0);

		for (int i = 0; i < v; i++) {
			int source = i;
			if (!visited[source]) {
				dfs_backEdge(i, visited, stack);
			}
		}

		return stack;
	}
};

class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		Graph g(graph.size());
		for (int i = 0; i < graph.size(); i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				g.addEdge(i, graph[i][j], false);
			}
		}
		vector<bool> pathvis = g.backEdge();
		vector<int> ans;
		for (int i = 0; i < pathvis.size(); i++) {
			if (!pathvis[i]) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};