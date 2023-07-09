class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(2, 1));
        int ans = INT_MIN;
        for (int i = 0; i < nums1.size(); i++) {
            if (i > 0) {
                if (nums1[i] >= nums1[i - 1]) {
                    dp[i][0] = max(dp[i][0], 1 + dp[i - 1][0]);
                }
                if (nums1[i] >= nums2[i - 1]) {
                    dp[i][0] = max(dp[i][0], 1 + dp[i - 1][1]);
                }
                if (nums2[i] >= nums2[i - 1]) {
                    dp[i][1] = max(dp[i][1], 1 + dp[i - 1][1]);
                }
                if (nums2[i] >= nums1[i - 1]) {
                    dp[i][1] = max(dp[i][1], 1 + dp[i - 1][0]);
                }
            }
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};