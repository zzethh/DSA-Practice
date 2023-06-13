class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int temp = 0;
        left[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            temp = temp + nums[i - 1];
            left[i] = temp;
        }
        temp = 0;
        right[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            temp = temp + nums[i + 1];
            right[i] = temp;
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(abs(left[i] - right[i]));
        }
        return ans;
    }
};