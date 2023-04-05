class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp) {
        if (i >= grid.size() or j >= grid[0].size()) {
            return INT_MAX;
        }
        if (i == grid.size() - 1 and j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) return dp[i][j];

        int down = helper(grid, i + 1, j, dp);
        int right = helper(grid, i, j + 1, dp);
        if (down != INT_MAX) down += grid[i][j];
        if (right != INT_MAX) right += grid[i][j];

        return dp[i][j] = min(down, right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return helper(grid, 0, 0, dp);
    }
};