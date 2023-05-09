class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        long long res = 0;
        vector<int> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        sort(nums.begin(), nums.end());
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            }
            else {
                int len = right - left;
                res = (res + power[len]) % mod;
                left++;
            }
        }
        return res;
    }
};