class Solution {
public:
    map<pair<int, int>, int> m;
    int helper(vector<int>& nums, int target, int sum, int i) {
        if (i == nums.size() and sum == target) {
            return 1;
        }
        if (i == nums.size()) {
            return 0;
        }
        if (m.find({i, sum}) != m.end()) return m[ {i, sum}];
        int plus = helper(nums, target, sum + nums[i], i + 1);
        int minus = helper(nums, target, sum - nums[i], i + 1);
        return m[ {i, sum}] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        return helper(nums, target, 0, 0);
    }
};