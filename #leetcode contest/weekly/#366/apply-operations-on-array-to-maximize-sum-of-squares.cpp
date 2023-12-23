class Solution {
public:
    int mod = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int barr[31];
        for (int i = 0; i < 31; i++) barr[i] = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int j = 0;
            while (x) {
                if (x & 1) barr[j]++;
                x = x >> 1;
                j++;
            }
        }

        for (int i = 0; i < k; i++) {
            long long sum = 0;
            for (int j = 0; j < 30; j++) {
                if (barr[j] > 0) {
                    sum = (sum + (long)pow(2, j));
                    barr[j]--;
                }
            }
            long long y = (sum % mod * sum % mod) % mod;
            ans = (ans % mod + y % mod) % mod;
        }
        return ans % mod;
    }
};