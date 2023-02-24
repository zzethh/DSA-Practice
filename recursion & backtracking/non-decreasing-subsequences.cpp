class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int> &nums, int prev, vector<int> temp, int i) {
        if (i == nums.size()) {
            if (temp.size() >= 2) s.insert(temp);
            return;
        }
        if (prev == INT_MAX or prev <= nums[i]) {
            temp.push_back(nums[i]);
            helper(nums, nums[i], temp, i + 1);
            temp.pop_back();
        }

        helper(nums, prev, temp, i + 1);

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        helper(nums, INT_MAX, temp, 0);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};