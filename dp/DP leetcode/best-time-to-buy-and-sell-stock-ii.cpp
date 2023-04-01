class Solution {
public:
    int helper(vector<int>& p, bool sold, int i, vector<vector<int>> &dp) {
        if (i == p.size()) {
            return 0;
        }
        if (dp[i][sold] != -1) return dp[i][sold];
        int profit = 0;
        int exc = 0;
        int exc2 = 0;
        if (sold) {
            profit = helper(p, false, i + 1, dp) - p[i];
            exc = helper(p, true, i + 1, dp);
        }
        else {
            profit = helper(p, true, i + 1, dp) + p[i];
            exc2 = helper(p, false, i + 1, dp);
        }
        return dp[i][sold] = max(profit, max(exc, exc2));
    }
    int helper2(vector<int> &p) {
        int n = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int sold = 0; sold < 2; sold++) {
                int profit = 0;
                int exc = 0;
                int exc2 = 0;
                if (sold) {
                    profit = dp[i + 1][0] - p[i];
                    exc = dp[i + 1][1];
                }
                else {
                    profit = dp[i + 1][1] + p[i];
                    exc2 = dp[i + 1][0];
                }
                dp[i][sold] = max(profit, max(exc, exc2));
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        ///return helper(prices,true,0,dp);
        return helper2(prices);
    }
};