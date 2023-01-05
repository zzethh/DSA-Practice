class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int mul = 1;
        if (n == 0) return mul;
        while (n > 0) {
            int x = n & 1;
            n = n >> 1;
            ans += (mul * (!x));
            mul = mul * 2;
        }
        return ans;
    }
};