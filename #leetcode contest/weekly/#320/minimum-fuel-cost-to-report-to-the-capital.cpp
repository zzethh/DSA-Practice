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
	long long dfshelper(int source, vector<bool> &visited, long long &sum, int seat) {
		// if (visited[source]) {
		// 	return 0;
		// }
		visited[source] = 1;
		int t = 1;
		for (auto x : l[source]) {
			if (!visited[x]) t += dfshelper(x, visited, sum, seat);
		}
		long long y = (t / seat);
		if (t % seat) y++;
		if (source != 0) sum += y;
		return t;
	}

	long long dfs(int source, int seat) {
		vector<bool> visited(v, 0);
		long long sum = 0;
		dfshelper(source, visited, sum, seat);
		return sum;
	}
};
class Solution {
public:
	long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		Graph g(roads.size() + 1);
		for (auto x : roads) {
			g.addEdge(x[0], x[1]);
		}
		return g.dfs(0, seats);
	}
};