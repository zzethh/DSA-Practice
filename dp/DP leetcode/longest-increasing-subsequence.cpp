class Solution {
public:
    int helper(vector<int> &nums, int prev, int i, vector<vector<int>>&dp) {
        if (i == nums.size()) return 0;
        if (dp[i][prev + 1] != 0) return dp[i][prev + 1];
        int inc = INT_MIN;
        if (prev == -1 or nums[i] > nums[prev]) {
            inc = 1 + helper(nums, i, i + 1, dp);
        }
        int exc = helper(nums, prev, i + 1, dp);
        return dp[i][prev + 1] = max(inc, exc);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1));
        return helper(nums, -1, 0, dp);
    }
};