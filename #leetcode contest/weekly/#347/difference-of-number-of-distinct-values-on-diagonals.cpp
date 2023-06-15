class Solution {
public:
    int upward(vector<vector<int>>& grid, int i, int j, int m, int n) {
        unordered_set<int> s;
        int k = i - 1;
        int l = j - 1;
        int cnt = 0;
        while (k >= 0 and l >= 0) {
            if (s.find(grid[k][l]) == s.end()) {
                s.insert(grid[k][l]);
                cnt++;
            }
            k--;
            l--;
        }
        // if(i!=k+1 and j!=l+1) return 1;
        // return 0;
        return cnt;
    }
    int lower(vector<vector<int>>& grid, int i, int j, int m, int n) {
        unordered_set<int> s;
        int k = i + 1;
        int l = j + 1;
        int cnt = 0;
        while (k < m and l < n) {
            if (s.find(grid[k][l]) == s.end()) {
                s.insert(grid[k][l]);
                cnt++;
            }
            k++;
            l++;
        }
        // if(i!=k-1 and j!=l-1) return 1;
        // return 0;
        return cnt;
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = abs(upward(grid, i, j, m, n) - lower(grid, i, j, m, n));
            }
        }
        return ans;
    }
};