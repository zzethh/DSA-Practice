class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) {
                int j = i;
                int len = 0;
                while (j < nums.size() and nums[j] == maxi) {
                    j++;
                    len++;
                }
                ans = max(ans, len);
                i = j;
            }
        }

        return ans;

    }
};