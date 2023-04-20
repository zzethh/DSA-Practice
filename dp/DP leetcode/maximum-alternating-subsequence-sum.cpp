class Solution {
public:
    long long helper(vector<int>&nums, bool even, int i, vector<vector<long long>> &dp) {
        if (i == nums.size()) return 0;
        if (dp[i][even] != INT_MIN) return dp[i][even];
        long long opt1 = 0, opt2 = 0;
        if (even) {
            opt1 = nums[i] + helper(nums, false, i + 1, dp);
            opt2 = helper(nums, true, i + 1, dp);
        }
        else if (!even) {
            opt1 = helper(nums, true, i + 1, dp) - nums[i];
            opt2 = helper(nums, false, i + 1, dp);
        }
        return dp[i][even] = max(opt1, opt2);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, INT_MIN));
        // long long dp[100001][2];
        // for(int i=0;i<100001;i++){
        //     dp[i][0]=INT_MIN;
        //     dp[i][1]=INT_MIN;
        // }
        return helper(nums, true, 0, dp);
    }
};