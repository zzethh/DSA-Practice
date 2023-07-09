class Solution {
public:
    //int ans=INT_MIN;
    int helper(vector<int> &nums, int target, int i, vector<int> &dp) {
        if (i == nums.size() - 1) {
            //ans=max(ans,cnt);
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int maxi = INT_MIN;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] - nums[i] <= target and nums[j] - nums[i] >= (-1 * target)) {
                maxi = max(maxi, helper(nums, target, j, dp));
                //cnt=cnt+1;
                //helper(nums,target,j,cnt+1);
            }
        }
        if (maxi == INT_MIN) return dp[i] = maxi;
        return dp[i] = 1 + maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        //int cnt=0;
        vector<int> dp(nums.size(), -1);
        int ans = helper(nums, target, 0, dp);
        //cout<<INT_MIN;
        if (ans == INT_MIN) return -1;
        return ans;
    }
};