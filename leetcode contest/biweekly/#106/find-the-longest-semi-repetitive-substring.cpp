class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int ans = 1;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j <= s.length() - i; j++) {
                string t = s.substr(i, j);
                bool pair = false;
                for (int k = 1; k < t.length(); k++) {
                    if (t[k] == t[k - 1] and pair == false) {
                        pair = true;
                    }
                    else if (t[k] == t[k - 1] and pair == true) {
                        ans = max(ans, k);
                        break;
                    }
                    ans = max(ans, k + 1);
                }
            }
        }
        return ans;
    }
};