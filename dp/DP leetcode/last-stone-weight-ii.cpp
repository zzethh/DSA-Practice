class Solution {
public:
    int helper(vector<int>& stones, int sum, int x, int total, int i, vector<vector<int>> &dp) {
        if (x >= sum or i == stones.size()) {
            return abs(x - (total - x));
        }
        if (dp[i][x] != -1) return dp[i][x];
        return dp[i][x] = min(helper(stones, sum, x + stones[i], total, i + 1, dp), helper(stones, sum, x, total, i + 1, dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto x : stones) {
            sum += x;
        }
        int total = sum;
        sum = ceil(sum / 2);
        vector<vector<int>> dp(stones.size() + 1, vector<int>(total, -1));
        return helper(stones, sum, 0, total, 0, dp);
    }
};