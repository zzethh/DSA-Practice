class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() - 1;
        int op1 = nums[n] - nums[2];
        int op2 = nums[n - 2] - nums[0];
        int op3 = nums[n - 1] - nums[1];
        cout << op1 << " " << op2;
        return min(op1, min(op2, op3));

    }
};