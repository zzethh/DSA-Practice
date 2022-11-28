class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        bool flag = 0;
        for (auto x : s) {
            m[x]++;
        }

        int len = 0;
        for (auto x : m) {
            len = len + (x.second / 2) * 2;
            if (x.second == 1 or x.second % 2 != 0) {
                flag = 1;
            }
        }
        if (flag) return len + 1;

        return len;
    }
};