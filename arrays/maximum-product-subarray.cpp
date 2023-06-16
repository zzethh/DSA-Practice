class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1;
        int suff = 1;
        int maxi = INT_MIN;
        for (auto x : nums) {
            pref *= x;
            maxi = max(maxi, pref);
            if (pref == 0) pref = 1;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            suff *= nums[i];
            maxi = max(maxi, suff);
            if (suff == 0) suff = 1;
        }
        return maxi;
    }
};