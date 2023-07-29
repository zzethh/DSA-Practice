class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int len = 1;
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                len++;
                left[i] = len;
            }
            else len = 1;
        }

        len = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] >= nums[i]) {
                len++;
                right[i] = len;
            }
            else len = 1;
        }
        vector<int> v;
        for (int i = k; i < n - k; i++) {
            if (left[i - 1] >= k and right[i + 1] >= k) {
                v.push_back(i);
            }
        }
        return v;
    }
};