class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        long long maxi = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            long long parts = ceil(nums[i] / (double)maxi);
            res += (parts - 1);
            maxi = nums[i] / parts;
        }
        return res;
    }
};