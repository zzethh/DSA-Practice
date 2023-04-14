class Solution {
public:
    int helper(int n, vector<int> &dp) {
        if (n == 0 or n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += helper(i - 1, dp) * helper(n - i, dp);
        }
        return dp[n] = sum;
    }
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};