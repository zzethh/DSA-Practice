class Solution {
public:
    vector<vector<int>> v;
    void helper(vector<int>& nums, int i) {
        if (i == nums.size()) {
            v.push_back(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++) {
            swap(nums[i], nums[k]);
            helper(nums, i + 1);
            swap(nums[i], nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums, 0);
        return v;
    }
};