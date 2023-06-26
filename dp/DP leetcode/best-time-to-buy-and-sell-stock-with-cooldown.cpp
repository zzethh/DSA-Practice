class Solution {
public:
    int helper(vector<int>& p, bool sold, int i, vector<vector<int>> &dp) {
        if (i >= p.size()) {
            return 0;
        }
        if (dp[i][sold] != -1) return dp[i][sold];
        int profit = INT_MIN;
        int exc = INT_MIN;
        int exc2 = INT_MIN;
        if (sold) {
            profit = helper(p, false, i + 1, dp) - p[i];
            exc = helper(p, true, i + 1, dp);
        }
        else {
            profit = helper(p, true, i + 2, dp) + p[i];
            exc2 = helper(p, false, i + 1, dp);
        }
        return dp[i][sold] = max(profit, max(exc, exc2));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(prices, true, 0, dp);
    }
};