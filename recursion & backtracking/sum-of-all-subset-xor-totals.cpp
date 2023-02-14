class Solution {
public:
    int cnt = 0;
    void helper(vector<int> &nums, int value, int i) {
        if (i == nums.size()) {
            cnt += value;
            return;
        }
        value = value ^ nums[i];
        helper(nums, value, i + 1);
        value = value ^ nums[i];
        helper(nums, value, i + 1);
    }
    int subsetXORSum(vector<int>& nums) {
        helper(nums, 0, 0);
        return cnt;
    }
};