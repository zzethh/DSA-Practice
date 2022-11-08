#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> matrix, vector<vector<bool>> &visited, vector<vectro<int>> &dp, int i, int j, int m, int n) {
	visited[i][j] = 1;

	int dx = { -1, 1, 0, 0};
	int dy = {0, 0, 1, -1};

	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx >= 0 and ny >= 0 and nx < m and ny<n and matrix[nx][ny]>matrix[i][j]) {
			int subprob = 0;
			if (visited[nx][ny]) {
				cnt = max(cnt, 1 + dp[nx][ny]);
			}
			else {
				dfs(matrix, visited, dp, nx, m, n);
				cnt = max(cnt, 1 + dp[nx][ny]);
			}
		}
	}
	dp[i][j] = cnt;

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