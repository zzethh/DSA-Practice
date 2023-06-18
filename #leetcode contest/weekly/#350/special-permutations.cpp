class Solution {
public:
    int mod = 1e9 + 7;
    int helper(vector<int>&nums, int prev, int i, int mask, vector<vector<int>> &dp) {
        if (i == nums.size()) return 1;
        if (dp[prev + 1][mask] != -1) return dp[prev + 1][mask];
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (mask & (1 << j)) {
                continue;
            }
            if (prev == -1 or nums[j] % nums[prev] == 0 or nums[prev] % nums[j] == 0) {
                ans += helper(nums, j, i + 1, mask | 1 << j, dp) % mod;
            }
        }
        return dp[prev + 1][mask] = ans % mod;
    }
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>((1 << 14) + 1, -1));
        return helper(nums, -1, 0, 0, dp) % mod;
    }
};