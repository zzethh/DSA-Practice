class Solution {
public:
	class graph {
		int v;
		list<int> *l;
		list<pair<int, int> > *l2;
	public:
		graph(int V) {
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

		void topodfs(int node, stack<int>&st, vector<int> &vis) {
			vis[node] = 1;
			for (auto nbr : l[node]) {
				if (!vis[nbr]) {
					topodfs(nbr, st, vis);
				}
			}
			st.push(node);
		}

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
	};
	vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
		graph g(numCourses);
		for (auto x : p) {
			g.addEdge(x[1], x[0], false);
		}
		if (!g.backEdge()) {
			vector<int> top;
			g.topo(top);
			return top;
		}
		return {};
	}
};