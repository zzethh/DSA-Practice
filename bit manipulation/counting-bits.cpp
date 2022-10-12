class Solution {
public:
    int count_bits(int n) {
        int cnt = 0;
        while (n > 0) {
            int last_bit = (n & 1);
            if (last_bit) cnt++;
            n = n >> 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        int ans = 0;
        vector<int> v;
        for (int i = 0; i <= n; i++) {
            v.push_back(count_bits(i));
        }

        return v;
    }
};