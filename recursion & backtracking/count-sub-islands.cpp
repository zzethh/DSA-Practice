class Solution {
public:
    int cnt = 0;
    void helper(vector<vector<int>>& grid2, int i, int j, int &m, int &n, vector<pair<int, int>> &v) {
        if (grid2[i][j] == 0) {
            return;
        }
        grid2[i][j] = 0;
        v.push_back({i, j});
        if ((i + 1 < m and grid2[i + 1][j] == 0) and (i - 1 >= 0 and grid2[i - 1][j] == 0) and (j + 1 < n and grid2[i][j + 1] == 0) and (j - 1 >= 0 and grid2[i][j - 1] == 0)) {
            return;
        }
        if (i + 1 < m and grid2[i + 1][j] == 1) helper(grid2, i + 1, j, m, n, v);
        if (i - 1 >= 0 and grid2[i - 1][j] == 1) helper(grid2, i - 1, j, m, n, v);
        if (j + 1 < n and grid2[i][j + 1] == 1) helper(grid2, i, j + 1, m, n, v);
        if (j - 1 >= 0 and grid2[i][j - 1] == 1) helper(grid2, i, j - 1, m, n, v);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<pair<int, int>>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 1) {
                    vector<pair<int, int>> v;
                    helper(grid2, i, j, m, n, v);
                    ans.push_back(v);
                }
            }
        }
        // for(int i=0;i<ans.size();i++){
        //     for(auto x:ans[i]){
        //         cout<<"{"<<x.first<<","<<x.second<<"},";
        //     }
        //     cout<<"-->"<<endl;
        // }
        int cnt = 0;
        for (int k = 0; k < ans.size(); k++) {
            cnt++;
            for (auto x : ans[k]) {
                int i = x.first;
                int j = x.second;
                if (grid1[i][j] == 0) {
                    //cout<<i<<","<<j<<endl;
                    cnt--;
                    break;
                }
            }
        }
        return cnt;
    }
};