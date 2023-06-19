class Solution {
public:
    void helper(vector<vector<char>>& grid2, int i, int j, int &m, int &n, vector<pair<int, int>> &v) {
        if (grid2[i][j] == '0') {
            return;
        }
        grid2[i][j] = '0';
        v.push_back({i, j});
        if ((i + 1 < m and grid2[i + 1][j] == '0') and (i - 1 >= 0 and grid2[i - 1][j] == '0') and (j + 1 < n and grid2[i][j + 1] == '0') and (j - 1 >= 0 and grid2[i][j - 1] == '0')) {
            return;
        }
        if (i + 1 < m and grid2[i + 1][j] == '1') helper(grid2, i + 1, j, m, n, v);
        if (i - 1 >= 0 and grid2[i - 1][j] == '1') helper(grid2, i - 1, j, m, n, v);
        if (j + 1 < n and grid2[i][j + 1] == '1') helper(grid2, i, j + 1, m, n, v);
        if (j - 1 >= 0 and grid2[i][j - 1] == '1') helper(grid2, i, j - 1, m, n, v);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    vector<pair<int, int>> v;
                    helper(grid, i, j, m, n, v);
                    ans.push_back(v);
                }
            }
        }
        // if(ans.empty()) cout<<"empty";
        // for(int i=0;i<ans.size();i++){
        //     for(auto x:ans[i]){
        //         cout<<"{"<<x.first<<","<<x.second<<"},";
        //     }
        //     cout<<"-->"<<endl;
        // }

        int cnt = 0;
        for (int k = 0; k < ans.size(); k++) {
            int startRow = INT_MAX;
            int endRow = INT_MIN;
            int startCol = INT_MAX;
            int endCol = INT_MIN;
            for (auto x : ans[k]) {
                int i = x.first;
                int j = x.second;
                startRow = min(i, startRow);
                endRow = max(i, endRow);
                startCol = min(j, startCol);
                endCol = max(j, endCol);
            }
            if (startRow >= 0 and endRow <= m - 1 and startCol >= 0 and endCol <= n - 1) {
                cnt++;
            }
        }
        return cnt;
    }
};