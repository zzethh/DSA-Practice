class Solution {
public:
    int cntbits(int n) {
        int cnt = 0;
        while (n > 0) {
            int last_bit = (n & 1);
            if (last_bit) cnt++;
            n = n >> 1;
        }
        return cnt;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (cntbits(i) == k) {
                cnt += nums[i];
            }
        }
        return cnt;
    }
};