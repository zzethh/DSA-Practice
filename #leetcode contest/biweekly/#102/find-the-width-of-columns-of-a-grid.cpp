class Solution {
public:
    int solve(int n) {
        if (n == 0) return 1;
        bool neg = false;
        if (n < 0) {
            neg = true;
            n = abs(n);
        }
        int cnt = 0;
        while (n > 0) {
            n = n / 10;
            cnt++;
        }
        // cout<<cnt<<endl;
        if (neg) return cnt + 1;
        return cnt;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> result;
        for (int j = 0; j < grid[0].size(); j++) {
            int ans = 0;
            for (int i = 0; i < grid.size(); i++) {
                ans = max(ans, solve(grid[i][j]));
            }
            result.push_back(ans);
        }
        return result;
    }
};