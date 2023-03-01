class Solution {
public:
    int helper(int idx, vector<int> &nums, int k, int n, vector<int> &dp) {
        if (idx == nums.size()) return 0;
        if (dp[idx] != -1) return dp[idx];
        int len = 0;
        int maxi = INT_MIN;
        int sum = 0;
        int ans = INT_MIN;
        for (int i = idx; i < min(idx + k, n); i++) {
            maxi = max(maxi, nums[i]);
            len++;
            sum = (len * maxi) + helper(i + 1, nums, k, n, dp);
            ans = max(ans, sum);
        }
        return dp[idx] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return helper(0, arr, k, n, dp);
    }
};