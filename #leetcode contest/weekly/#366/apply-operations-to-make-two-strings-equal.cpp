class Solution {
public:
    int helper(vector<int> &d, int i, int x, int n, vector<vector<int>> &dp) {
        if (i == d.size()) return 0;
        if (dp[i][n] != -1) return dp[i][n];
        int res = INT_MAX;
        if (i < d.size() - 1) {
            res = min(res, d[i + 1] - d[i] + helper(d, i + 2, x, n, dp));
        }
        res = min(res, x + helper(d, i + 1, x, n + 1, dp));
        if (n > 0) res = min(res, helper(d, i + 1, x, n - 1, dp));
        return dp[i][n] = res;
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> d;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) d.push_back(i);
        }
        if (d.size() % 2) return -1;
        vector<vector<int>> dp(502, vector<int>(502, -1));
        return helper(d, 0, x, 0, dp);
    }
};