class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int mini = INT_MAX;
        int r = 0, l = 0;
        int len = 0;
        while (r < nums.size()) {
            sum += nums[r];
            r++;
            len++;
            while (sum >= target) {
                if (sum >= target) mini = min(mini, len);
                sum -= nums[l];
                len--;
                l++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};