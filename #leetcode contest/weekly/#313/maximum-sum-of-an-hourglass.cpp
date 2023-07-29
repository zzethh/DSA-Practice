class Solution {
public:
    int findsum(vector<vector<int>> &grid, int i, int j, int m, int n) {
        if (i + 2 >= m or j + 2 >= n) return INT_MIN;
        int sum = 0;
        for (int k = i; k < i + 3; k++) {
            for (int l = j; l < j + 3; l++) {
                sum += grid[k][l];
            }
        }
        sum = sum - grid[i + 1][j] - grid[i + 1][j + 2];
        return sum;
    }
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, findsum(grid, i, j, m, n));
            }
        }
        return ans;
    }
};