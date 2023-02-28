class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        int temp = 1;
        for (int i = 0; i < nums.size(); i++) {
            left[i] = temp;
            temp *= nums[i];
        }
        temp = 1;
        for (int j = nums.size() - 1; j >= 0; j--) {
            right[j] = temp;
            temp *= nums[j];
        }
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};