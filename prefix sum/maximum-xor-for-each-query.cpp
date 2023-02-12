class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int temp = 0;
        vector<int> pref;
        for (auto x : nums) {
            temp = temp ^ x;
            pref.push_back(temp);
        }
        vector<int> v;
        for (auto x : pref) {
            int k = maximumBit;
            int ans = 0;
            int mul = 1;
            while (k--) {
                int f = x & 1;
                x = x >> 1;
                int n;
                if (f == 0) n = 1;
                else n = 0;
                ans = ans + (n * mul);
                mul = mul * 2;
            }
            v.push_back(ans);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};