class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n, INT_MIN);
        vector<int> left(n, INT_MIN);
        int maxl = INT_MIN;
        int maxr = INT_MIN;
        for (int i = 1; i < n; i++) {
            maxl = max(maxl, nums[i - 1]);
            left[i] = maxl;
        }
        for (int i = n - 2; i >= 0; i--) {
            maxr = max(maxr, nums[i + 1]);
            right[i] = maxr;
        }
        long long ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            ans = max(ans, (long long)(left[i] - nums[i]) * right[i]);
        }
        return ans;
    }
};