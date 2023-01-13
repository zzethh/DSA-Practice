class Solution {
public:
    int helper(vector<int> &prices, int &fee, int i, bool sold, vector<vector<int>> &dp) {
        if (i == prices.size()) {
            return 0;
        }

        if (dp[i][sold] != -1) return dp[i][sold];

        int profit = 0;
        if (sold) {
            //buy
            int inc = -prices[i] + helper(prices, fee, i + 1, 0, dp);
            //wait it out
            int skip = helper(prices, fee, i + 1, 1, dp);
            profit = max(inc, skip);
        }
        else {
            //sell
            int inc = prices[i] - fee + helper(prices, fee, i + 1, 1, dp);
            //wait it out
            int skip = helper(prices, fee, i + 1, 0, dp);
            profit = max(inc, skip);
        }
        return dp[i][sold] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return helper(prices, fee, 0, 1, dp);
    }
};