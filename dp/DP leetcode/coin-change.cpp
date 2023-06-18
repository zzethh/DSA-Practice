class Solution {
public:
    int helper(vector<int>& coins, int amt, vector<int> &dp) {
        if (amt == 0) return 0;
        if (amt < 0) return INT_MAX;
        if (dp[amt] != -1) return dp[amt];
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            mini = min(mini, helper(coins, amt - coins[i], dp));
        }
        if (mini == INT_MAX) return dp[amt] = mini;
        return dp[amt] = mini + 1;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = helper(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};