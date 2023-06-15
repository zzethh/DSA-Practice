class Solution {
public:
    bool check(int mid, vector<int> &nums, int k) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                i++;
                total++;
            }
        }
        return total >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = INT_MAX - 10;
        int ans = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, nums, k)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};