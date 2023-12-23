class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> v = nums;
        sort(nums.begin(), nums.end());
        if (v == nums) return true;
        sort(nums.begin(), nums.end(), greater());
        if (v == nums) return true;
        return false;
    }
};