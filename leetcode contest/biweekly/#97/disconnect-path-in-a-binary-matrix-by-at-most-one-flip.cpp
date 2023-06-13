class Solution {
public:
    bool ans = false;
    bool helper(vector<vector<int>>& grid, int i, int j, int &cnt) {
        if (i == grid.size() - 1 and j == grid[0].size() - 1) {
            return true;
        }
        if (grid[i][j] == 0) {
            return false;
        }
        if (i == 0 and j == 0) grid[i][j] = grid[i][j];
        else grid[i][j] = 0;


        if (i < grid.size() - 1) {
            bool subprob1 = helper(grid, i + 1, j, cnt);
            if (subprob1) return true;
        }

        if (j < grid[0].size() - 1) {
            bool subprob2 = helper(grid, i, j + 1, cnt);
            if (subprob2) return true;
        }
        return false;
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int i = 0;
        int j = 0;
        int cnt = 0;
        int a = grid.size() - 1;
        int b = grid[0].size() - 1;
        if (a + 1 == 1 and b + 1 == 2 and grid[0][1] and grid[0][0]) return false;
        // for(int m=0;m<grid.size();m++){
        //     for(int n=0;n<grid[0].size();n++){
        //         cout<<grid[m][n]<<" ";
        //     }
        //     cout<<endl;
        // }
        bool flag1 = helper(grid, i, j, cnt);
        bool flag2 = helper(grid, i, j, cnt);
        if (flag1 and flag2) return false;
        // cout<<endl;
        // for(int m=0;m<grid.size();m++){
        //     for(int n=0;n<grid[0].size();n++){
        //         cout<<grid[m][n]<<" ";
        //     }
        //     cout<<endl;
        // }

        return true;
    }
};