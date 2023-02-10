class Solution {
public:
    bool helper(vector<int> nums, int a, int b, int l, int r, int size) {
        if (a >= b and size == 0) {
            return true;
        }
        if (l > r) {
            return false;
        }
        if (l == r) {
            return helper(nums, a + nums[l], b, l + 1, r, size - 1);
        }

        bool one = false;
        bool four = false;

        if (l + 1 < nums.size()) {
            one = helper(nums, a + nums[l], b + nums[l + 1], l + 2, r, size - 2);
        }

        bool two = helper(nums, a + nums[l], b + nums[r], l + 1, r - 1, size - 2);
        bool three = helper(nums, a + nums[r], b + nums[l], l + 1, r - 1, size - 2);

        if (r - 1 >= 0) {
            four = helper(nums, a + nums[r], b + nums[r - 1], l, r - 2, size - 2);
        }

        if (one or two or three or four) return true;
        return false;
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, 0, 0, nums.size() - 1, nums.size());
    }
};