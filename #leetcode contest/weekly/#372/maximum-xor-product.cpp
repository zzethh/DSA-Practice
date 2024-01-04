
class Solution {
public:
    int mod = 1e9 + 7;
    int maximumXorProduct(long long a, long long b, int n) {
        for (int i = n - 1; i >= 0; i--) {
            long long mask = (long long)1 << i;
            if ((a & mask) and (b & mask)) {
                continue;
            }
            else if ((a & mask)) {
                if (a > b) {
                    a = a ^ mask;
                    b = b | mask;
                }
                continue;
            }
            else if ((b & mask)) {
                if (a < b) {
                    b = b ^ mask;
                    a = a | mask;
                }
            }
            else {
                a = a | mask;
                b = b | mask;
            }
        }
        a = a % mod;
        b = b % mod;
        long long ans = (long long)1 * a * b;
        return ans % mod;
    }
};