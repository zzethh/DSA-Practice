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
	long long dfshelper(int source, vector<bool> &visited, long long &ans, int &seat) {
		visited[source] = 1;
		long long pass = 1;
		for (auto x : l[source]) {
			if (!visited[x]) {
				pass += dfshelper(x, visited, ans, seat);
			}
		}
		long long cost = pass / seat;
		if (pass % seat) cost++;

		if (source != 0) ans += cost;
		return pass;
	}

	void dfs(int source, long long &ans, int &seat) {
		vector<bool> visited(v, 0);
		dfshelper(source, visited, ans, seat);
	}
};
class Solution {
public:
	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		Graph g(roads.size() + 1);
		for (auto x : roads) {
			g.addEdge(x[0], x[1]);
		}
		long long ans = 0;
		g.dfs(0, ans, seats);
		return ans;
	}
};