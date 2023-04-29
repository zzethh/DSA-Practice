class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j) {
        if (i >= grid.size() or j >= grid[0].size() or i == -1 or j == -1) return 0;
        if (grid[i][j] == 0) return 0;

        int temp = grid[i][j];
        grid[i][j] = 0;
        int down = helper(grid, i + 1, j);
        int up = helper(grid, i - 1, j);
        int right = helper(grid, i, j + 1);
        int left = helper(grid, i, j - 1);
        // v[i][j]=0;

        return left + right + down + up + temp;
        // return temp+max(max(left,right),max(up,down));
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    // vector<vector<bool>> v(m,vector<bool>(n,0));
                    maxi = max(maxi, helper(grid, i, j));
                }
            }
        }
        //vector<vector<bool>> v(m,vector<bool>(n,0));
        ///return helper(grid,0,0,v);
        return maxi;
    }
};