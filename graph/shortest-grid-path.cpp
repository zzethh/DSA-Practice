#include<bits/stdc++.h>
using namespace std;

class graph {
	int v;
	list<pair<int, int>> *l;
public:
	graph(int V) {
		v = V;
		l = new list<pair<int, int>>[v];
	}

	void addEdge(int x, int y, int wt, bool undir = true) {
		l[x].push_back({y, wt});
		if (undir) {
			l[y].push_back({x, wt});
		}
	}
};

// class cmp {
// public:
// 	bool operator()(vector<int> a, vector<int> b) {
// 		return a[0] < b[0];
// 	}
// };

int shortest_path(vector<vector<int>> grid) {
	int m = grid.size();
	int n = grid[0].size();

	int i = 0;
	int j = 0;

	vector < vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX)) ;
	set<vector<int>> s;

	dist[i][j] = grid[0][0];

	s.insert({dist[0][0], 0, 0});

	int dx[] = {0, 0, 1, -1};
	int dy[] = {1, -1, 0, 0};

	while (!s.empty()) {
		auto it = s.begin();
		vector<int> v = *(it);
		int curr_dist = v[0];
		int cx = v[1];
		int cy = v[2];
		s.erase(it);

		for (int k = 0; k < 4; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if (nx >= 0 and nx<m and ny >= 0 and ny < n and curr_dist + grid[nx][ny] < dist[nx][ny]) {
				auto f = s.find({dist[nx][ny], nx, ny});
				if (f != s.end()) {
					s.erase(f);
				}

				int new_dist = curr_dist + grid[nx][ny];
				dist[nx][ny] = new_dist;
				s.insert({new_dist, nx, ny});
			}
		}

	}

	return dist[m - 1][n - 1];
}


int main() {
	vector<vector<int>> v
	{
		{31 , 100, 64, 12, 18},
		{10 , 13 , 47, 157, 6},
		{100 , 113 , 174 , 11 , 33},
		{88 , 124 , 41 , 20 , 140},
		{99 , 32, 111, 41, 20}
	};

	cout << shortest_path(v);
	return 0;
}