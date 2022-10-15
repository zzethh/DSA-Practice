class Solution {
public:

    void helper(vector<int> nums, vector<vector<int>> &v, vector<int> ans, int i) {
        if (i == nums.size()) {
            v.push_back(ans);
            return;
        }

        helper(nums, v, ans, i + 1);

        ans.push_back(nums[i]);
        helper(nums, v, ans, i + 1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> v;
        int i = 0;
        vector<int> ans;
        helper(nums, v, ans, i);
        return v;
    }
};