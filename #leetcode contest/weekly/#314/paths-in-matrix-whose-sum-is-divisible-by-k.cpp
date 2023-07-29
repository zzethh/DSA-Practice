class Solution {
public:
    int mod = 1e9 + 7;
    //int ans=0;
    //unordered_map<string,int> mp;
    int helper(vector<vector<int>>& grid, int &k, int i, int j, int &m, int &n, int sum, vector<vector<vector<int>>> &dp) {
        if (i == m - 1 and j == n - 1 and (sum + grid[i][j]) % k == 0) {
            return 1;
        }
        if (dp[i][j][sum % k] != -1) return dp[i][j][sum % k];
        if (i >= m) {
            return 0;
        }
        if (j >= n) {
            return 0;
        }
        int right = helper(grid, k, i, j + 1, m, n, sum + grid[i][j], dp) % mod;
        int down = helper(grid, k, i + 1, j, m, n, sum + grid[i][j], dp) % mod;
        // mp[s]=(right+down)%mod;
        return dp[i][j][sum % k] = (right + down) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        // unordered_map<string,int> mp;
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(51, -1)));
        int ans = helper(grid, k, 0, 0, m, n, 0, dp);
        return ans;
    }
};