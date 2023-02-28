class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int temp = 0;
        for (int i = 0; i < n; i++) {
            left[i] = temp;
            temp += nums[i];
        }
        temp = 0;
        for (int i = n - 1; i >= 0; i--) {
            right[i] = temp;
            temp += nums[i];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int l = (i * nums[i]) - left[i];
            int r = right[i] - ((n - i - 1) * nums[i]);
            ans.push_back(l + r);
        }
        return ans;
    }
};