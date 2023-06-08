class Solution {
public:
    bool ispossible(vector<int>&nums, int p, int diff) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= diff) {
                p--;
                i++;
            }
        }
        return p <= 0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int right = nums[nums.size() - 1] - nums[0];
        int left = 0;
        int ans = right;
        while (left <= right) {
            int mid = (right + left) / 2;
            if (ispossible(nums, p, mid)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};