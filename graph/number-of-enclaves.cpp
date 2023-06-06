class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));

        // for(int i=0;i<m;i++){
        //     if(grid[i][0]==1) q.push({i,0});
        //     if(grid[i][n-1]==1) q.push({i,n-1});
        // }
        // for(int j=1;j<n-1;j++){
        //     if(grid[0][j]==1) q.push({0,j});
        //     if(grid[m-1][j]==1) q.push({m-1,j});
        // }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0 or i == m - 1 or j == n - 1) {
                    if (grid[i][j]) {
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            int i = f.first;
            int j = f.second;
            vis[i][j] = 1;
            if (i + 1 < m and grid[i + 1][j] == 1 and vis[i + 1][j] == 0) {
                q.push({i + 1, j});
            }
            if (i - 1 >= 0 and grid[i - 1][j] == 1 and vis[i - 1][j] == 0) {
                q.push({i - 1, j});
            }
            if (j + 1 < n and grid[i][j + 1] == 1 and vis[i][j + 1] == 0) {
                q.push({i, j + 1});
            }
            if (j - 1 >= 0 and grid[i][j - 1] == 1 and vis[i][j - 1] == 0) {
                q.push({i, j - 1});
            }
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 and grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//dfs

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &A) {
        if ( i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] == 0)
            return 0;

        A[i][j] = 0;

        return 1 + dfs(i - 1, j, A) + dfs(i + 1, j, A) + dfs(i, j - 1, A) + dfs(i, j + 1, A);
    }
    int numEnclaves(vector<vector<int>>& A) {
        int all_one = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++)
                all_one += A[i][j];
        }
        int close_one = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                if ((i == 0 || j == 0 || i == A.size() - 1 || j == A[0].size() - 1) && A[i][j] == 1)
                    close_one += dfs(i, j, A);
            }
        }
        return all_one - close_one;
    }
};