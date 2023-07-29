class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1;
        int j = 0;
        for (int i = 0; i < n; i++) {
            int temp = nums[i] + k;
            int cnt = 0;
            while (j<nums.size() and temp >= nums[j] - k) {
                cnt++;
                j++;
            }
            ans = max(ans, j - i);
            if (j == n) break;
        }
        return ans;
    }
};