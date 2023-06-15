class Solution {
public:
    int helper(string s) {
        int i = 0;
        int j = s.length() - 1;
        int len = 0;
        while (i < j) {
            if (s[i] == '1') return 0;
            if (s[j] == '0') return 0;
            if (s[i] == '0' and s[j] == '1') {
                i++;
                j--;
                len++;
            }
        }

        return len * 2;
    }
    int findTheLongestBalancedSubstring(string s) {
        int ans = INT_MIN;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j < s.length() - i + 1; j++) {
                ans = max(ans, helper(s.substr(i, j)));
            }
        }

        return ans;
    }
};