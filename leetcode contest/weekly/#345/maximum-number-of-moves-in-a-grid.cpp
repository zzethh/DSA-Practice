class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int &m, int &n, vector<vector<int>> &dp) {
        if (i<0 or i >= m or j >= n) {
            return 0;
        }
        if ((i - 1 >= 0 and j + 1<n and grid[i][j] >= grid[i - 1][j + 1]) and (j + 1<n and grid[i][j] >= grid[i][j + 1]) and (i + 1 < m and j + 1<n and grid[i][j] >= grid[i + 1][j + 1])) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int left = 0;
        int right = 0;
        int center = 0;
        if (i - 1 >= 0 and j + 1 < n and grid[i - 1][j + 1] > grid[i][j]) left = 1 + helper(grid, i - 1, j + 1, m, n, dp);
        if (j + 1 < n and grid[i][j + 1] > grid[i][j]) center = 1 + helper(grid, i, j + 1, m, n, dp);
        if (i + 1 < m and j + 1 < n and grid[i + 1][j + 1] > grid[i][j]) right = 1 + helper(grid, i + 1, j + 1, m, n, dp);

        return dp[i][j] = max(left, max(center, right));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i < m; i++) {
            maxi = max(maxi, helper(grid, i, 0, m, n, dp));
        }
        return maxi;
    }
};