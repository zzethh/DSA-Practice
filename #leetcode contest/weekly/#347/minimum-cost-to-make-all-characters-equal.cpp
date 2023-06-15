class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != s[i + 1]) {
                ans += min(i + 1, (int)s.length() - i - 1);
            }
        }
        return ans;
    }
};