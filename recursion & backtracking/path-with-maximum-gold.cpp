class Solution {
public:
    int maxi = 0;
    void helper(vector<vector<int>> &grid, int i, int j, int gold) {
        if (i<0 or i >= grid.size() or j<0 or j >= grid[0].size() or grid[i][j] == 0) {
            maxi = max(maxi, gold);
            return;
        }

        gold += grid[i][j];
        int temp = grid[i][j];
        grid[i][j] = 0;
        helper(grid, i + 1, j, gold);
        helper(grid, i - 1, j, gold);
        helper(grid, i, j + 1, gold);
        helper(grid, i, j - 1, gold);
        grid[i][j] = temp;
        return;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    helper(grid, i, j, 0);
                }
            }
        }
        return maxi;
    }
};