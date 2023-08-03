class Solution {
public:
    bool helper(vector<int> &nums, int sum, int x, int i, vector<vector<int>> &dp) {
        if (i == nums.size()) {
            return false;
        }
        if (x == sum - x and sum != 0) {
            return true;
        }
        if (dp[i][x] != -1) return dp[i][x];
        bool first = helper(nums, sum, x + nums[i], i + 1, dp);
        bool second = helper(nums, sum, x, i + 1, dp);
        if (first or second) return dp[i][x] = true;
        return dp[i][x] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (auto x : nums) {
            sum += x;
        }
        vector<vector<int>> dp(nums.size(), vector<int>(sum + 1, -1));
        return helper(nums, sum, 0, 0, dp);
    }
};