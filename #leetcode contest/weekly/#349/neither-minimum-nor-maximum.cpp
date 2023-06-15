class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= n; i++) {
            if (i != 0 and i != n) {
                return nums[i];
            }
        }
        return -1;
    }
};