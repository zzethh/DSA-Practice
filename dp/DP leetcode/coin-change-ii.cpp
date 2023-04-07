class Solution {
public:
    int helper(int amount, vector<int>& coins, int i, vector<vector<int>> &dp) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0) {
            return 0;
        }
        if (i == coins.size()) {
            return 0;
        }

        if (dp[i][amount] != -1) return dp[i][amount];

        int cnt = 0;
        for (int idx = i; idx < coins.size(); idx++) {
            cnt += helper(amount - coins[idx], coins, idx, dp);
        }
        return dp[i][amount] = cnt;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(amount, coins, 0, dp);
    }
};