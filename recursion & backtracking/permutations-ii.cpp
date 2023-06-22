class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& nums, int i) {
        if (i == nums.size()) {
            s.insert(nums);
            return;
        }
        for (int k = i; k < nums.size(); k++) {
            swap(nums[i], nums[k]);
            helper(nums, i + 1);
            swap(nums[i], nums[k]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};