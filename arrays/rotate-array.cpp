class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(nums.size(), 0);
        for (int i = 0; i < n; i++) {
            v[(i + k) % n] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = v[i];
        }
    }
};